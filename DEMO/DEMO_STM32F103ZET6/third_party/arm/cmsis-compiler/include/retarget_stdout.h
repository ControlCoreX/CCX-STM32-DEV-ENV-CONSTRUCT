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

#ifndef RETARGET_STDOUT_H__
#define RETARGET_STDOUT_H__

#ifdef  __cplusplus
extern "C"
{
#endif

/// Put a character to the stdout
/// \param[in]   ch  Character to output
/// \return the character written, or -1 on write error
int stdout_putchar (int ch);

#ifdef  __cplusplus
}
#endif

#endif /* RETARGET_STDOUT_H__ */
