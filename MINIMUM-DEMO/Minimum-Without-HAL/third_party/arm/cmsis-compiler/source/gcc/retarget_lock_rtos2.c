/*
 * Copyright (C) 2023 ARM Limited or its affiliates. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "retarget_os.h"

#if defined(_RETARGETABLE_LOCKING) && (_RETARGETABLE_LOCKING == 1)
/*
  Retargeting routines implementation using CMSIS-RTOS2.

  Multi-threaded applications are required to provide an implementation for
  all __retarget routines and static locks defined in sys/lock.h.
  If some routines or static locks are missing, the link fails with doubly
  defined symbols.
*/
#include <stdlib.h>
#include "cmsis_compiler.h"
#include "cmsis_os2.h"

/* Lock structure holds mutex object pointer */
struct __lock {
  int   irqmask;
  void *mutex;
};

/* Newlib mutexes */
struct __lock __lock___sinit_recursive_mutex  = {0};
struct __lock __lock___sfp_recursive_mutex    = {0};
struct __lock __lock___atexit_recursive_mutex = {0};
struct __lock __lock___at_quick_exit_mutex    = {0};
struct __lock __lock___malloc_recursive_mutex = {0};
struct __lock __lock___env_recursive_mutex    = {0};
struct __lock __lock___tz_mutex               = {0};
struct __lock __lock___dd_hash_mutex          = {0};
struct __lock __lock___arc4random_mutex       = {0};


/* Check if function is called from thread of from irq. */
__STATIC_INLINE int is_irq_mode (void) {
  if (__get_IPSR() == 0U) {
    return 0; /* Thread mode  */
  } else {
    return 1; /* Handler mode */
  }
}

/* Check if interrupts are masked (i.e. disabled) */
__STATIC_INLINE int is_irq_masked (void) {
#if   ((defined(__ARM_ARCH_7M__)        && (__ARM_ARCH_7M__        != 0)) || \
       (defined(__ARM_ARCH_7EM__)       && (__ARM_ARCH_7EM__       != 0)) || \
       (defined(__ARM_ARCH_8M_MAIN__)   && (__ARM_ARCH_8M_MAIN__   != 0)) || \
       (defined(__ARM_ARCH_8_1M_MAIN__) && (__ARM_ARCH_8_1M_MAIN__ != 0)))
  return ((__get_PRIMASK() != 0U) || (__get_BASEPRI() != 0U));
#else
  return (__get_PRIMASK() != 0U);
#endif
}

/* Initialize a mutex */
static osMutexId_t mutex_init (uint32_t attr_bits) {
  osMutexId_t id;
  osMutexAttr_t attr;

  attr.name      = NULL;
  attr.attr_bits = osMutexPrioInherit | attr_bits;
  attr.cb_mem    = NULL;
  attr.cb_size   = 0U;

  id = osMutexNew (&attr);

  return (id);
}

/* Acquire mutex */
static int mutex_acquire (osMutexId_t *p_mutex, uint32_t attr_bits, uint32_t timeout) {
  osMutexId_t id;
  int rval = -1;

  id = *p_mutex;

  if (id == NULL) {
    /* Create mutex */
    id = mutex_init (attr_bits);

    /* Set mutex id */
    *p_mutex = id;
  }

  if (id != NULL) {
    if (osKernelGetState() == osKernelRunning) {
      /* Kernel is running, acquire mutex */
      if (osMutexAcquire (id, timeout) == osOK) {
        rval = 0;
      }
    }
  }

  return (rval);
}

/* Release mutex */
static int mutex_release (osMutexId_t id) {
  int rval = -1;

  if (osMutexRelease (id) == osOK) {
    rval = 0;
  }
  return (rval);
}

/* Free mutex object */
static int mutex_deinit (osMutexId_t *id) {
  int rval = -1;

  if (osMutexDelete (id) == osOK) {
    rval = 0;
  }
  return (rval);
}


/* Allocate lock related resources */
void __retarget_lock_init (_LOCK_T *lock) {
  /* Allocate lock structure */
  *lock = malloc(sizeof(struct __lock));

  if (*lock != NULL) {
    /* Initialize lock object */
    (*lock)->mutex = mutex_init (0U);
  } else {
    /* Out of memory */
    abort();
  }
}


/* Allocate recursive lock related resources */
void __retarget_lock_init_recursive (_LOCK_T *lock) {
  /* Allocate lock structure */
  *lock = malloc(sizeof(struct __lock));

  if (*lock != NULL) {
    /* Initialize lock object */
    (*lock)->mutex = mutex_init (osMutexRecursive);
  } else {
    /* Out of memory */
    abort();
  }
}


/* Free lock related resources */
void __retarget_lock_close (_LOCK_T lock) {
  __retarget_lock_close_recursive (lock);
}


/* Free recursive lock related resources */
void __retarget_lock_close_recursive (_LOCK_T lock) {
  /* Delete lock object */
  (void)mutex_deinit(lock->mutex);

  /* Free lock structure */
  free(lock);
}


/* Acquire lock immediately after the lock object is available */
void __retarget_lock_acquire (_LOCK_T lock) {

  if (is_irq_mode() == 1) {
    /* Called from irq context */
    if (is_irq_masked() == 0) {
      /* Interrupts are not disabled */
      __disable_irq();

      /* Set lock variable */
      lock->irqmask = 1;
    }
  }
  else {
    (void)mutex_acquire (&lock->mutex, 0U, osWaitForever);
  }
}


/* Acquire recursive lock immediately after the lock object is available */
void __retarget_lock_acquire_recursive (_LOCK_T lock) {

  if (is_irq_mode() == 1) {
    /* Called from irq context */
    if (is_irq_masked() == 0) {
      /* Interrupts are not disabled */
      __disable_irq();

      /* Set lock variable */
      lock->irqmask = 1;
    }
  }
  else {
    (void)mutex_acquire (&lock->mutex, osMutexRecursive, osWaitForever);
  }
}


/* Acquire lock if the lock object is available */
int __retarget_lock_try_acquire (_LOCK_T lock) {
  int rval;

  if (is_irq_mode() == 1) {
    /* Called from irq context */
    rval = -1;
  } else {
    rval = mutex_acquire (&lock->mutex, 0U, 0U);
  }

  /* Return zero for success and non-zero to indicate that the lock cannot be acquired */
  return (rval);
}


/* Acquire recursive lock if the lock object is available */
int __retarget_lock_try_acquire_recursive (_LOCK_T lock) {
  int rval;

  if (is_irq_mode() == 1) {
    /* Called from irq context */
    rval = -1;
  } else {
    rval = mutex_acquire (&lock->mutex, osMutexRecursive, 0U);
  }

  /* Return zero for success and non-zero to indicate that the lock cannot be acquired */
  return (rval);
}


/* Relinquish the lock ownership */
void __retarget_lock_release (_LOCK_T lock) {
  __retarget_lock_release_recursive (lock);
}


/* Relinquish the recursive lock ownership */
void __retarget_lock_release_recursive (_LOCK_T lock) {

  if (lock->irqmask == 1) {
    /* Lock acquire disabled interrupts, clear lock variable */
    lock->irqmask = 0;

    /* Re-enable interrupts */
    __enable_irq();
  }
  else {
    (void)mutex_release (lock->mutex);
  }
}
#endif /* _RETARGETABLE_LOCKING */
