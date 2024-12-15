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

#include "RTE_Components.h"

#ifdef RTE_CMSIS_Compiler_STDERR
#include "retarget_stderr.h"
#endif

#ifdef RTE_CMSIS_Compiler_STDIN
#include "retarget_stdin.h"
#endif

#ifdef RTE_CMSIS_Compiler_STDOUT
#include "retarget_stdout.h"
#endif

#if defined(RTE_CMSIS_Compiler_STDIN)
/**
  Get a character from the stdio

  \return     The next character from the input, or -1 on read error.
*/
static int stdin_getc(FILE *file) {
  (void)file;
  return stdin_getchar();
}

static FILE __stdin = FDEV_SETUP_STREAM(NULL,
                                        stdin_getc,
                                        NULL,
                                        _FDEV_SETUP_READ);
FILE *const stdin = &__stdin;

#endif

#if defined(RTE_CMSIS_Compiler_STDOUT)
/**
  Put a character to the stdout

  \param[in]   ch  Character to output
  \return          The character written, or -1 on write error.
*/
static int stdout_putc(char c, FILE *file) {
  (void)file;
  return stdout_putchar(c);
}

static FILE __stdout = FDEV_SETUP_STREAM(stdout_putc,
                                         NULL,
                                         NULL,
                                         _FDEV_SETUP_WRITE);
FILE *const stdout = &__stdout;
#endif


#if defined(RTE_CMSIS_Compiler_STDERR)
/**
  Put a character to the stderr

  \param[in]   ch  Character to output
  \return          The character written, or -1 on write error.
*/
static int stderr_putc(char c, FILE *file) {
  (void)file;
  return stderr_putchar(c);
}

static FILE __stderr = FDEV_SETUP_STREAM(stderr_putc,
                                         NULL,
                                         NULL,
                                         _FDEV_SETUP_WRITE);
FILE *const stderr = &__stderr;
#endif

/* Terminate a process */
__attribute__((weak, __noreturn__))
void _exit (int status) {
  for(;;){ ; }
}
