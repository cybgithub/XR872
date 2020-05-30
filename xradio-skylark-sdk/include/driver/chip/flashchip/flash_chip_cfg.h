/*
 * Copyright (C) 2017 XRADIO TECHNOLOGY CO., LTD. All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *    1. Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *    2. Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the
 *       distribution.
 *    3. Neither the name of XRADIO TECHNOLOGY CO., LTD. nor the names of
 *       its contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _DRIVER_CHIP_FLASHCHIP_FLASH_CHIP_CFG_H_
#define _DRIVER_CHIP_FLASHCHIP_FLASH_CHIP_CFG_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define FLASH_DEFAULTCHIP

#ifndef __CONFIG_BOOTLOADER

#define FLASH_M25P64

#define FLASH_PN25F16B

#define FLASH_W25Q16FW

#define FLASH_PN25F08

#define FLASH_PN25F16

#define FLASH_XT25F16B
#define FLASH_XT25F32B
#define FLASH_XT25F64B

#define FLASH_XM25QH16B

#define FLASH_XM25QH32B

#define FLASH_BY25Q64AS

#define FLASH_BY25Q32BS

#define FLASH_BY25D16

#define FLASH_BY25D80

#define FLASH_P25Q80H

#define FLASH_P25Q40H

#define FLASH_P25Q16H

#define FLASH_P25Q64H

#define FLASH_EN25Q80B

#define FLASH_EN25QH16A

#define FLASH_EN25Q32C

#define FLASH_EN25QH64A

#define FLASH_XM25QH64A

#define FLASH_GD25Q256D

#endif /* __CONFIG_BOOTLOADER */


typedef struct _FlashChipCfg {
	uint32_t mJedec;
	uint32_t mSize;

	uint32_t mMaxFreq;
	uint32_t mMaxReadFreq;

	uint32_t mEraseSizeSupport;
	uint16_t mReadSupport;
	uint16_t mReadStausSupport;
	uint8_t  mWriteStatusSupport;
	uint8_t  mPageProgramSupport;
} FlashChipCfg;

const FlashChipCfg *FlashChipGetCfgList(int32_t *len);

#ifdef __cplusplus
}
#endif

#endif /* _DRIVER_CHIP_FLASHCHIP_FLASH_CHIP_CFG_H_ */
