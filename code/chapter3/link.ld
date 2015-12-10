/***************************
* 文件名: link.ld   
***************************/

ENTRY(start)
SECTIONS
{
	. = 0x100000;

	.text :
	{
		*(.text)
		. = ALIGN(4096);
	}
	.data :
	{
		*(.data)
		*(.rodata)
		. = ALIGN(4096);
	}
}

