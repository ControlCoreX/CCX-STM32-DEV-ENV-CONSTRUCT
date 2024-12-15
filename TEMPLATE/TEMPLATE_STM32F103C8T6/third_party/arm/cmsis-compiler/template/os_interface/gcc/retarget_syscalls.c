/*-----------------------------------------------------------------------------
 * Name:    retarget_syscalls.c
 * Purpose: System Call Routines Retarget Template
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

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/* Open file */
int _open (const char *path, int oflag, ...) {
  // ...
  return (-1);
}


/* Close a file descriptor */
int _close (int fildes) {
  // ...
  return (-1);
}


/* Write on a file */
ssize_t _write (int fildes, const void *buf, size_t nbyte) {
  // ...
  return (-1);
}


/* Read from a file */
ssize_t _read (int fildes, void *buf, size_t nbyte) {
  // ...
  return (-1);
}


/* Move the read/write file offset */
off_t _lseek (int fildes, off_t offset, int whence) {
  // ...
  return (-1);
}


/* Test for a terminal device */
int _isatty (int fildes) {
  // ...
  return (0);
}


/* Get file status */
int _fstat (int fildes, struct stat *buf) {
  // ...
  return (-1);
}


/* Link one file to another file */
int _link(const char *path1, const char *path2) {
  // ...
  return (-1);
}


/* Remove a directory entry */
int _unlink (const char *path) {
  // ...
  return (-1);
}


/* Execute a file */
int _execve(const char *path, char *const argv[], char *const envp[]) {
  // ...
  return -1;
}


/* Create a new process */
pid_t fork (void) {
  // ...
  return -1;
}


/* Terminate a process */
void _exit (int status) {
  // ...
}


/* Send a signal to a process or a group of processes */
int _kill (pid_t pid, int sig) {
  // ...
  return -1;
}


/* Get the current process id */
pid_t _getpid (void) {
  // ...
  return 0;
}

/* Wait for a child process to stop or terminate */
pid_t _wait (int *stat_loc) {
  // ...
  return -1;
}


/* Extend heap space by incr bytes */
void *_sbrk (ptrdiff_t incr) {
  // ...
  return -1;
}
