/****************************************************
# File        : kernel.c
# Blog        : www.cnblogs.com/lucasysfeng
# Author      : lucasysfeng
# Description : 内核入口函数
****************************************************/
#include "kprint.h"

int kernel_main()
{ 
    print_clear();

    print_str("hello world, print is OK\n");
    print_dec(123);
    print_char('\n');
    print_dec(-123);
    print_char('\n');
    print_hex(11);

    return 0;
}
