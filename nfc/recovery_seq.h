/******************************************************************************
 *  Copyright (C) 2021 NXP
 *   *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 ******************************************************************************/
#if defined(RECOVERY_ENABLE)

#ifndef __RECOVERY_SEQ_H_
#define __RECOVERY_SEQ_H_

#include "common.h"

#define MAX_FRAME_SIZE 0x22A /* support for 256(0x100) & 554(0x22A) frame size*/

#define MAX_DATA_SIZE \
  (MAX_FRAME_SIZE - FW_CRC_LEN - FW_HDR_LEN)

#define FW_ROM_CODE_VER_OFFSET 4
#define FW_MAJOR_VER_OFFSET 7
#define RECOVERY_FW_SUPPORTED_ROM_VER 0x01
#define RECOVERY_FW_SUPPORTED_MAJOR_VER 0x10
#define RECOVERY_FW_MJ_VER_OFFSET 5

#define DL_SET_HDR_FRAGBIT(n) \
  ((n) | (1 << 10)) /* Header chunk bit set macro */
#define DL_CLR_HDR_FRAGBIT(n) \
  ((n) & ~(1U << 10)) /* Header chunk bit clear macro */

#define DL_FRAME_RESP_LEN 0x04
#define DL_FRAME_RESP_LEN_OFFSET 1
#define DL_FRAME_RESP_STAT_OFFSET 2
#define DL_SEGMENTED_FRAME_RESP_STAT1 0x2D
#define DL_SEGMENTED_FRAME_RESP_STAT2 0x2E
#define DL_NON_SEGMENTED_FRAME_RESP_STAT 0x00
#define DL_INVALID_CRC_VALUE 0xffffU
#define DL_CRC_MASK 0xff

#define SHIFT_MASK 0x00FF
#define MSB_POS 8

/* Data buffer for frame to write */
typedef struct recovery_frame {
	uint32_t len;
	uint8_t p_buffer[MAX_FRAME_SIZE];
} recovery_frame_t;

/* Contains Info about user buffer and last data frame */
typedef struct recovery_info {
	uint32_t currentReadOffset; /* current offset within the user buffer to read/write */
	uint32_t remBytes;          /* Remaining bytes to write */
	uint16_t wRemChunkBytes;   /* Remaining bytes within the chunked frame */
	bool bFrameSegmented;  /* Indicates the current frame is segmented */
} recovery_info_t;

/* indicates the error codes for nfc recovery module */
typedef enum recovery_status {
	STATUS_SUCCESS = 0x00,
	STATUS_FAILED = 0x01,
} recovery_status_t;

/** @brief   Function to recover the nfcc.
 *  @param   nfc_dev nfc driver object.
 *  @return status code of type recovery_status_t.
 */
recovery_status_t do_recovery(nfc_dev_t *nfc_dev);
#endif// end  __RECOVERY_SEQ_H_
#endif
