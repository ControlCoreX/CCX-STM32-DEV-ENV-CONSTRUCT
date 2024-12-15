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

#ifndef RETARGET_OS_H__
#define RETARGET_OS_H__

/*
  The rt_heap.h header file defines the interface for retargeting the heap implementation.

  It provides a way for users to customize the way that the heap is managed, by
  defining their own functions for allocating and deallocating memory.
*/
#include <rt_heap.h>

/*
  The rt_locale.h header file enables the retargetting of the locale mechanism.

  It is used to override the default behavior of the locale-related functions
  and to provide custom locale functionality.
*/
#include <rt_locale.h>

/*
  The rt_misc.h header file contains definitions for various retargetable functions.

  It includes functions like _getenv_init(), _clock_init(), __user_libspace(),
  __rt_lib_init(), __ARM_get_argv(), __rt_lib_shutdown(), __rt_exit(),
  __user_initial_stackheap(), __user_heap_extent() and __user_stack_slop() which are
  responsible for the initialization, shutdown, and memory allocation of various
  parts of the library.

  The header file also includes various structures like __initial_stackheap,
  __heap_extent, and __stack_slop, which can be defined by users to give bounds
  on the heap and stack address space.
*/
#include <rt_misc.h>

/*
  The time.h header file provides declarations for types, macros, and functions
  for manipulating time.

  It defines macros, types, and functions that deal with calendar time, handle
  local time expressed for a specific time zone and Daylight Savings Time.
*/
#include <time.h>

#ifdef  __cplusplus
extern "C"
{
#endif

/// Retrieve thread local storage
void *__user_perthread_libspace (void);

/// Mutex type definition
struct rt_mutex_s;
typedef struct rt_mutex_s rt_mutex_t;

/// Initialize mutex
/// \param[in]  mutex     Pointer to mutex object
/// \return nonzero value on success, otherwise the function returns 0
int _mutex_initialize(rt_mutex_t *mutex);

/// Acquire mutex
/// \param[in]  mutex     Pointer to mutex object
void _mutex_acquire(rt_mutex_t *mutex);

/// Release mutex
/// \param[in]  mutex     Pointer to mutex object
void _mutex_release(rt_mutex_t *mutex);

/// Free mutex
/// \param[in]  mutex     Pointer to mutex object
void _mutex_free(rt_mutex_t *mutex);

#ifdef  __cplusplus
}
#endif

#endif /* RETARGET_OS_H__ */
