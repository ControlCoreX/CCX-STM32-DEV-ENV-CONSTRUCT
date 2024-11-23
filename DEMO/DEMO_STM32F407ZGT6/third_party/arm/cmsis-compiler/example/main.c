/*---------------------------------------------------------------------------
 * Copyright (c) 2023 Arm Limited (or its affiliates). All rights reserved.
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
 *---------------------------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>

#include "RTE_Components.h"
#include  CMSIS_device_header

#include "retarget_stdout.h"

extern int stdout_init (void);

int main (void) {
  uint32_t count;

  stdout_init();

  printf("Starting ...\r\n");

  while (1)  {
    /* Use printf via USART to output "Hello World" lines */
    for (count = 1U; count <= 10U; count++) {
      printf ("Hello World %u\r\n", (unsigned int)count);
    }

    printf("\r\nFinished\r\n\x04");
  }

  return 0;
}
