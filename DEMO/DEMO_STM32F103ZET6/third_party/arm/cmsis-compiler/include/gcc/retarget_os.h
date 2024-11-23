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
  The unistd.h header file contains declarations for types, constants and functions
  that provide access to system services.

  It defines functions that perform operations like file I/O, process management and
  inter-process communication.
*/
#include <unistd.h>

/*
  The fcntl.h header file contains declarations for functions, constants, and types
  that provide access to operations on file descriptors.
*/
#include <fcntl.h>

/*
  The time.h header file provides declarations for types, macros, and functions
  for manipulating time.

  It defines macros, types, and functions that deal with calendar time, handle
  local time expressed for a specific time zone and Daylight Savings Time.
*/
#include <time.h>

/*
  The stdio.h header file provides declarations for input and output operations.
*/
#include <stdio.h>


//  ==== Locking Routines ====

/// \fn void __retarget_lock_init(_LOCK_T *lock)
/// \brief Allocate lock related resources.
/// \param[in]  lock  pointer to user defined lock object

/// \fn void __retarget_lock_init_recursive(_LOCK_T *lock)
/// \brief Allocate recursive lock related resources.
/// \param[in]  lock  pointer to user defined lock object

/// \fn void __retarget_lock_close(_LOCK_T lock)
/// \brief Free lock related resources.
/// \param[in]  lock  user defined lock object

/// \fn void __retarget_lock_close_recursive(_LOCK_T lock)
/// \brief Free recursive lock related resources.
/// \param[in]  lock  user defined lock object

/// \fn void __retarget_lock_acquire(_LOCK_T lock)
/// \brief Acquire lock immediately after the lock object is available.
/// \param[in]  lock  user defined lock object

/// \fn void __retarget_lock_acquire_recursive(_LOCK_T lock)
/// \brief Acquire recursive lock immediately after the lock object is available.
/// \param[in]  lock  user defined lock object

/// \fn int __retarget_lock_try_acquire(_LOCK_T lock)
/// \brief Acquire lock if the lock object is available.
/// \param[in]  lock  user defined lock object
/// \return zero for success and non-zero to indicate that the lock cannot be acquired

/// \fn int __retarget_lock_try_acquire_recursive(_LOCK_T lock)
/// \brief Acquire recursive lock if the lock object is available.
/// \param[in]  lock  user defined lock object
/// \return zero for success and non-zero to indicate that the lock cannot be acquired

/// \fn void __retarget_lock_release(_LOCK_T lock)
/// \brief Relinquish the lock ownership.
/// \param[in]  lock  user defined lock object

/// \fn void __retarget_lock_release_recursive(_LOCK_T lock)
/// \brief Relinquish the recursive lock ownership.
/// \param[in]  lock  user defined lock object

#endif /* RETARGET_OS_H__ */
