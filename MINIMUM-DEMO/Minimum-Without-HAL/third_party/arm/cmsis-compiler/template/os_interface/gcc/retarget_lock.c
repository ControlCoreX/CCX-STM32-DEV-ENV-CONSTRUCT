/*-----------------------------------------------------------------------------
 * Name:    retarget_lock.c
 * Purpose: Locking Routines Retarget Template
 * Rev.:    1.0.0
 *-----------------------------------------------------------------------------*/

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

#include <stdio.h>

/* Lock structure definition */
struct __lock {
  /* ... */
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


/* Allocate lock related resources */
void __retarget_lock_init (_LOCK_T *lock) {
  /* .. */
}


/* Allocate recursive lock related resources */
void __retarget_lock_init_recursive (_LOCK_T *lock) {
  /* .. */
}


/* Free lock related resources */
void __retarget_lock_close (_LOCK_T lock) {
  /* .. */
}


/* Free recursive lock related resources */
void __retarget_lock_close_recursive (_LOCK_T lock) {
  /* .. */
}


/* Acquire lock immediately after the lock object is available */
void __retarget_lock_acquire (_LOCK_T lock) {
  /* .. */
}


/* Acquire recursive lock immediately after the lock object is available */
void __retarget_lock_acquire_recursive (_LOCK_T lock) {
  /* .. */
}


/* Acquire lock if the lock object is available */
int __retarget_lock_try_acquire (_LOCK_T lock) {
  /* .. */
  return -1;
}


/* Acquire recursive lock if the lock object is available */
int __retarget_lock_try_acquire_recursive (_LOCK_T lock) {
  /* .. */
  return -1;
}


/* Relinquish the lock ownership */
void __retarget_lock_release (_LOCK_T lock) {
  /* .. */
}


/* Relinquish the recursive lock ownership */
void __retarget_lock_release_recursive (_LOCK_T lock) {
  /* .. */
}
