/****************************************************
# File        : kernel.c
# Blog        : www.cnblogs.com/lucasysfeng
# Author      : lucasysfeng
# Description : 内核入口函数
****************************************************/

int kernel_main()
{ 
    // 显存开始地址 
    char *display_buf = (char*)0xb8000;         

    // 清屏 
    unsigned int i = 0;
    const unsigned int total = 80 * 25 * 2;      // 一屏25行，每行80个字符，每个字符2个字节
    while(i < total) 
    {
        display_buf[i++] = ' ';
        display_buf[i++] = 0x04;                 // 颜色 
    }

    // 显示字符
    const char *str = "Hello World, welcome to kernel!";
    for (i = 0; '\0' != *str;)
    {
        display_buf[i++] = *(str++);
        display_buf[i++] = 0x04;
    }

    return 0;
}
