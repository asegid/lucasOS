/****************************************************
 # File        : kprint.c
 # Blog        : www.cnblogs.com/lucasysfeng
 # Author      : lucasysfeng
 # Description : 打印函数
 ****************************************************/
#include "common.h"

// 一屏25行
#define LINE_COUNT 25
// 一行80个字符
#define LINE_LENGTH 80
// 字符颜色
#define COLOR 0x04

// 显存开始地址
static unsigned short *display_buf = (unsigned short *) 0xb8000;
// 字符属性
static const unsigned short char_attr = COLOR << 8;

// 当前光标的坐标
static unsigned char cursor_x = 0;
static unsigned char cursor_y = 0;

/**
 * 清屏
 */
void print_clear()
{
	unsigned int i;
	for (i = 0; i < LINE_COUNT * LINE_LENGTH; i++)
	{
		display_buf[i] = 0x20 | char_attr;
	}

	cursor_x = 0;
	cursor_y = 0;
}

/**
 * 滚屏（输出大于80行时）
 */
static void scroll()
{
	if (cursor_y >= LINE_COUNT)
	{
		unsigned int i;
		for (i = 0; i < (LINE_COUNT - 1) * LINE_LENGTH; i++)
		{
			display_buf[i] = display_buf[i + LINE_LENGTH];
		}

		for (i = (LINE_COUNT - 1) * LINE_LENGTH; i < LINE_COUNT * LINE_LENGTH; i++)
		{
			display_buf[i] = 0x20 | char_attr;
		}
		cursor_y = 24;
	}
}

/**
 * 打印一个字符（为简化逻辑，某些特殊字符均作为换行符处理）
 */
void print_char(const char c)
{
	if (c >= ' ')
	{
		display_buf[cursor_y * LINE_LENGTH + cursor_x] = c | char_attr;
		cursor_x++;
	}
	else
	{
		cursor_x = 0;
		cursor_y++;
	}

	// 每行80个字符，满80个字符换行
	if (cursor_x >= 80)
	{
		cursor_x = 0;
		cursor_y++;
	}

	scroll();
}

/**
 * 打印以\0结尾的字符串
 */
void print_str(const char* str)
{
	while (*str)
	{
		print_char(*str++);
	}
}

/**
 * 打印十进制数
 */
void print_dec(int num)
{
	char str[12] =
	{ '\0' };
	kitoa(num, str, 10);
	print_str(str);
}

/**
 * 打印十六进制数
 */
void print_hex(int num)
{
	char str[14] =
	{ '0', 'x', '\0' };
	kitoa(num, &(str[2]), 16);
	print_str(str);
}
