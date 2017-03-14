
#pragma once

#include "../common/types.h"
#include "../mcu/compiler.h"

enum{
	FLASH_WRITE_STATUS_CMD	=	0x01,
	FLASH_WRITE_CMD			=	0x02,
	FLASH_READ_CMD			=	0x03,
	FLASH_WRITE_ENABLE_CMD 	= 	0x06,
	FLASH_WRITE_DISABLE_CMD = 	0x04,
	FLASH_READ_STATUS_CMD	=	0x05,
	FLASH_READ_STATUS_CMD1	=	0x35,
	FLASH_SECT_ERASE_CMD	=	0x20,
	FLASH_BLK_ERASE_CMD		=	0xD8,
	FLASH_POWER_DOWN		=	0xB9,
	FLASH_GET_JEDEC_ID		=	0x9F,
};

enum{
	FLASH_NONE	                    =	0,
	FLASH_GD25Q40_0x00000_0x1ffff,
	FLASH_GD25Q40_0x00000_0x3ffff,
	FLASH_GD25Q40_0x00000_0x6ffff,
	FLASH_GD25Q40_0x40000_0x7ffff,
	
	FLASH_MD25D40_0x00000_0x3ffff  = 0x11,
	FLASH_MD25D40_0x00000_0x6ffff,
};

enum{
	FLASH_ID_GD25Q40 = 0xc8400013,
	FLASH_ID_MD25D40 = 0x51400013,
};

_attribute_ram_code_ void flash_erase_sector(u32 addr);
_attribute_ram_code_ void flash_erase_block(u32 addr);
/*_attribute_ram_code_ */void flash_write_page(u32 addr, u32 len, u8 *buf);
_attribute_ram_code_ void flash_read_page(u32 addr, u32 len, u8 *buf);
_attribute_ram_code_ u32 flash_get_jedec_id();

void flash_get_id();
int flash_protect_disable();
int flash_protect_up256k();
int flash_protect_down256k();
int flash_protect_8266_normal();
int flash_protect_OTA_copy();
int flash_protect_8267_normal();
int flash_protect_8267_OTA_clr_flag();
int flash_unprotect_OTA_start();
int flash_protect_OTA_data_erase();
void flash_protect_debug();

