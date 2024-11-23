/*-----------------------------------------------------------------------------
 * Name:    retarget_fs.c
 * Purpose: File Interface Retarget Template
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

#include "retarget_fs.h"

/* Open a file */
int32_t rt_fs_open (const char *path, int32_t mode) {
  // ...
  return (RT_ERR);
}

/* Close a file */
int32_t rt_fs_close (int32_t fd) {
  // ...
  return (RT_ERR);
}

/* Write to a file */
int32_t rt_fs_write (int32_t fd, const void *buf, uint32_t cnt) {
  // ...
  return (RT_ERR);
}

/* Read from a file */
int32_t rt_fs_read (int32_t fd, void *buf, uint32_t cnt) {
  // ...
  return (RT_ERR);
}

/* Move the file position pointer */
int64_t rt_fs_seek (int32_t fd, int64_t offset, int32_t whence) {
  // ...
  return (RT_ERR);
}

/* Get file size */
int64_t rt_fs_size (int32_t fd) {
  // ...
  return (RT_ERR);
}

/* Get file status information */
int32_t rt_fs_stat (int32_t fd, rt_fs_stat_t *stat) {
  // ...
  return (RT_ERR);
}

/* Remove a file or directory */
int32_t rt_fs_remove (const char *path) {
  // ...
  return (RT_ERR);
}

/* Rename or move a file or directory */
int32_t rt_fs_rename (const char *oldpath, const char *newpath) {
  // ...
  return (RT_ERR);
}
