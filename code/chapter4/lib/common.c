/****************************************************
 # File        : common.h
 # Blog        : www.cnblogs.com/lucasysfeng
 # Author      : lucasysfeng
 # Description : 公共函数
 ****************************************************/

/**
 * 数字转换为字符串
 */
void kitoa(int num, char *str, unsigned int radix)
{
	char tmpchar;
	char *firstdig;
	unsigned int remainder;

	// 如果是负数，首字符存负号
	if (num < 0)
	{
		*str++ = '-';
		num = -num;
	}

	firstdig = str;                     //保存第一个数字，为最后的字符串逆序转换做准备。

	while (num)
	{
		remainder = num % radix;
		num = num / radix;
		*str++ = (remainder > 9) ? (remainder - 10 + 'a') : (remainder + '0');
	}
	*str = '\0';

	str--;
	while (firstdig < str)
	{
		tmpchar = *str;
		*str = *firstdig;
		*firstdig = tmpchar;
		firstdig++;
		str--;
	}
}
