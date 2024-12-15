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

size_t __read(int handle, unsigned char *buf, size_t bufSize)
{
#if defined(RTE_CMSIS_Compiler_STDIN)
  if (handle == 0)
  {
    size_t nChars = 0;
    for (size_t i = bufSize; i > 0; --i)
    {
      const int c = stdin_getchar();
      if (c < 0) {
        break;
      } 
      *buf++ = (unsigned char)c;
      nChars++;
    }
    return nChars;
  }
#endif

  return -1;
}

#endif

#if defined(RTE_CMSIS_Compiler_STDOUT) || defined(RTE_CMSIS_Compiler_STDERR)

size_t __write(int handle, const unsigned char *buf, size_t bufSize)
{
  /* Check for the command to flush all handles */
  if (handle == -1)
  {
    return 0;
  }

#if defined(RTE_CMSIS_Compiler_STDOUT)  
  if (handle == 1 /* stdout */) {
    for (size_t i = bufSize; i > 0; --i)
    {
      stdout_putchar(*buf++);
    }
    return bufSize;
  }
#endif

#if defined(RTE_CMSIS_Compiler_STDERR)
  if (handle == 2 /* stderr */) {
    for (size_t i = bufSize; i > 0; --i)
    {
      stderr_putchar(*buf);
      ++buf;
    }
    return bufSize;
  }
#endif
  return -1;
}

#endif
