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

#ifndef RETARGET_FS_H__
#define RETARGET_FS_H__

#ifdef  __cplusplus
extern "C"
{
#endif

#include <stdint.h>

/// File Open Mode definitions
#define RT_OPEN_RDONLY        0x0000       ///< Open file for reading only
#define RT_OPEN_WRONLY        0x0001       ///< Open file for writing only
#define RT_OPEN_RDWR          0x0002       ///< Open file for reading and writing
#define RT_OPEN_APPEND        0x0008       ///< Open file in append mode
#define RT_OPEN_CREATE        0x0100       ///< Create file if it does not exist
#define RT_OPEN_TRUNCATE      0x0200       ///< Truncate existing file

/// File Attribute definitions
#define RT_ATTR_FILE          0x0001       ///< File is a regular file
#define RT_ATTR_DIR           0x0002       ///< File is a directory
#define RT_ATTR_LINK          0x0004       ///< File is a symbolic link
#define RT_ATTR_RD            0x0100       ///< File read is permitted
#define RT_ATTR_WR            0x0200       ///< File write is permitted

/// File Seek Operation definitions
#define RT_SEEK_SET           0            ///< Set position offset from the start of the file
#define RT_SEEK_CUR           1            ///< Set position offset from the current location
#define RT_SEEK_END           2            ///< Set position offset from the end of the file

/// File Operation Return Codes
#define RT_ERR                (-1)         ///< Unspecified error
#define RT_ERR_NOTSUP         (-2)         ///< Not supported
#define RT_ERR_INVAL          (-3)         ///< Invalid argument
#define RT_ERR_IO             (-4)         ///< Low level I/O error
#define RT_ERR_NOTFOUND       (-5)         ///< File not found
#define RT_ERR_EXIST          (-6)         ///< File already exists
#define RT_ERR_ISDIR          (-7)         ///< File is a directory
#define RT_ERR_NOSPACE        (-8)         ///< Not enough space or out of memory
#define RT_ERR_READONLY       (-9)         ///< File is read only
#define RT_ERR_FILEDES        (-10)        ///< File descriptor error (out of range, file not open, w/r to file opened in r/w mode)
#define RT_ERR_MAXPATH        (-11)        ///< File or path name is too long
#define RT_ERR_BUSY           (-12)        ///< File is busy, access is denied
#define RT_ERR_NOTEMPTY       (-13)        ///< Directory is not empty
#define RT_ERR_MAXFILES       (-14)        ///< Too many files open
#define RT_ERR_OVERFLOW       (-15)        ///< Value overflows the specified range


/// Time and Date Information
typedef struct rt_fs_time_s {
  uint16_t year;                           ///< Year
  uint8_t  mon;                            ///< Month of year [0, 11]
  uint8_t  day;                            ///< Day of month [1, 31]
  uint8_t  hour;                           ///< Hours   [0, 23]
  uint8_t  min;                            ///< Minutes [0, 59]
  uint8_t  sec;                            ///< Seconds [0, 60]
  uint8_t  rsvd;                           ///< Reserved
} rt_fs_time_t;

///File Status Information
typedef struct rt_fs_stat_s {
  uint32_t     attr;                       ///< File attribute bitmap
  rt_fs_time_t access;                     ///< Last file data access timestamp
  rt_fs_time_t modify;                     ///< Last file data modification timestamp
  rt_fs_time_t change;                     ///< Last file object change timestamp
  uint32_t     blksize;                    ///< The size of filesystem block
  uint32_t     blkcount;                   ///< Number of allocated filesystem blocks
} rt_fs_stat_t;


/// Open a file
/// \param[in]     path    string specifying the pathname of the file to be opened
/// \param[in]     mode    integer bitmap specifying the file open mode
/// \return a non-negative integer representing the file descriptor on success, or error code on failure
int32_t rt_fs_open (const char *path, int32_t mode);

/// Close a file
/// \param[in]     fd      file descriptor of an opened file
/// \return zero if the file was successfully closed, or error code on failure
int32_t rt_fs_close (int32_t fd);

/// Write to a file
/// \param[in]     fd      file descriptor of an opened file
/// \param[in]     buf     pointer to the buffer containing data to write
/// \param[in]     cnt     number of bytes to write
/// \return number of bytes actually written, or error code on failure
int32_t rt_fs_write (int32_t fd, const void *buf, uint32_t cnt);

/// Read from a file
/// \param[in]     fd      file descriptor of an opened file
/// \param[out]    buf     pointer to the buffer to store read data
/// \param[in]     cnt     number of bytes to read
/// \return number of bytes actually read, 0 at the EOF, or error code on failure
int32_t rt_fs_read (int32_t fd, void *buf, uint32_t cnt);

/// Move the file position pointer
/// \param[in]     fd      file descriptor of an opened file
/// \param[in]     offset  the number of bytes to move
/// \param[in]     whence  file position location (RT_SEEK_SET, RT_SEEK_CUR, RT_SEEK_END)
/// \return current file position from the beginning of the file, or error code on failure
int64_t rt_fs_seek (int32_t fd, int64_t offset, int32_t whence);

/// Get file size
/// \param[in]     fd      file descriptor of an opened file
/// \return file size in bytes, or error code on failure
int64_t rt_fs_size (int32_t fd);

/// Get file status information
/// \param[in]     fd      file descriptor of an opened file
/// \param[out]    stat    pointer to a rt_fs_stat_t object to store the status information in
/// \return zero if the file status was successfully retrieved, or error code on failure
int32_t rt_fs_stat (int32_t fd, rt_fs_stat_t *stat);

/// Remove a file or directory
/// \param[in]     path    string specifying the pathname
/// \return zero if the file or directory was successfully removed, or error code on failure
int32_t rt_fs_remove (const char *path);

/// Rename or move a file or directory
/// \param[in]     oldpath string specifying file or directory to be renamed
/// \param[in]     newpath string specifying the new pathname
/// \return zero if the file or directory was successfully renamed or moved, or error code on failure
int32_t rt_fs_rename (const char *oldpath, const char *newpath);

#ifdef  __cplusplus
}
#endif

#endif /* RETARGET_FS_H__ */
