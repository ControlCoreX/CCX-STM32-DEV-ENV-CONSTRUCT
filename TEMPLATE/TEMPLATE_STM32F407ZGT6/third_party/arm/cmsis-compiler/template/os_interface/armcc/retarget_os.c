/*-----------------------------------------------------------------------------
 * Name:    retarget_os.c
 * Purpose: OS Interface Retarget Template
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

/* Mutex identifier */
typedef void *mutex;

/* Mutex function prototypes */
int  _mutex_initialize(mutex *m);
void _mutex_acquire   (mutex *m);
void _mutex_release   (mutex *m);
void _mutex_free      (mutex *m);

/* Initialize mutex */
int _mutex_initialize(mutex *m) {
  /* .. */
  return 0;
}

/* Acquire mutex */
void _mutex_acquire(mutex *m) {
  /* .. */
}

/* Release mutex */
void _mutex_release(mutex *m) {
  /* .. */
}

/* Free mutex */
void _mutex_free(mutex *m) {
  /* .. */
}
