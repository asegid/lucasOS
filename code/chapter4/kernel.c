/****************************************************
 # File        : kernel.c
 # Blog        : www.cnblogs.com/lucasysfeng
 # Author      : lucasysfeng
 # Description : 内核入口函数
 ****************************************************/
#include "kprint.h"
#include "multiboot.h"

void show_memory_map()
{
	uint32_t mmap_addr = glb_mboot_ptr->mmap_addr;
	uint32_t mmap_length = glb_mboot_ptr->mmap_length;

	mmap_entry_t *mmap = (mmap_entry_t *) mmap_addr;
	for (mmap = (mmap_entry_t *) mmap_addr;
			(uint32_t) mmap < mmap_addr + mmap_length; mmap++)
	{
		print_hex((uint32_t) mmap->base_addr_low);
		print_char('\n');
	}
}

int kernel_main()
{
	print_clear();

	print_str("memory map is below\n");

	show_memory_map();

	return 0;
}
