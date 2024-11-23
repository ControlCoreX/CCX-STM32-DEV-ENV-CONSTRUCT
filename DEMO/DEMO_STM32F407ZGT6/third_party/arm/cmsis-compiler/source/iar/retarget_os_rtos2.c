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

#include "cmsis_os2.h"
#include "cmsis_compiler.h"

/* Check if the kernel has been initialized */
static uint32_t os_kernel_is_initialized (void) {
  if (osKernelGetState() > osKernelInactive) {
    return 1U;
  } else {
    return 0U;
  }
}

/* Check if the kernel is running */
static uint32_t os_kernel_is_running (void) {
  if (osKernelGetState() == osKernelRunning) {
    return 1U;
  } else {
    return 0U;
  }
}

/* Check if processor is in Thread or Handler mode */
static uint32_t is_thread_mode (void) {
  if (__get_IPSR() == 0U) {
    return 1U; /* Thread mode  */
  } else {
    return 0U; /* Handler mode */
  }
}

/* Define retarget mutex structure to hold mutex identifier */
struct rt_mutex_s {
  osMutexId_t id;
};

#pragma language=save
#pragma language=extended
/* Initialize mutex */
__USED void __iar_system_Mtxinit(struct rt_mutex_s *mutex)
{
  if (os_kernel_is_initialized()) {
    mutex->id = osMutexNew(NULL);
  }
}

/* Acquire mutex */
__USED void __iar_system_Mtxlock(struct rt_mutex_s *mutex)
{
  if (os_kernel_is_running() && is_thread_mode()) {
    (void)osMutexAcquire(mutex->id, osWaitForever);
  }
}

/* Release mutex */
__USED void __iar_system_Mtxunlock(struct rt_mutex_s *mutex) // Unlock a system lock
{
  if (os_kernel_is_running() && is_thread_mode()) {
    (void)osMutexRelease(mutex->id);
  }
}

/* Free mutex */
__USED void __iar_system_Mtxdst(struct rt_mutex_s *mutex)    // Destroy a system lock
{
  (void)osMutexDelete(mutex->id);
}

//#endif //defined(_DLIB_THREAD_SUPPORT) && _DLIB_THREAD_SUPPORT > 0

/* Initialize mutex */
__USED void __iar_file_Mtxinit(struct rt_mutex_s *mutex)
{
  if (os_kernel_is_initialized()) {
    mutex->id = osMutexNew(NULL);
  }
}

/* Acquire mutex */
__USED void __iar_file_Mtxlock(struct rt_mutex_s *mutex)
{
  if (os_kernel_is_running() && is_thread_mode()) {
    (void)osMutexAcquire(mutex->id, osWaitForever);
  }
}

/* Release mutex */
__USED void __iar_file_Mtxunlock(struct rt_mutex_s *mutex) // Unlock a system lock
{
  if (os_kernel_is_running() && is_thread_mode()) {
    (void)osMutexRelease(mutex->id);
  }
}

/* Free mutex */
__USED void __iar_file_Mtxdst(struct rt_mutex_s *mutex)    // Destroy a system lock
{
  (void)osMutexDelete(mutex->id);
}

#pragma language=restore
