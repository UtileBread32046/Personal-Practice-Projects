#include <stdio.h>

int main()
{
	printf("%d\n", 36 + 64);
	// 理论上可进行连续赋值 (e.g.) c = b = a + 3;
	// 但为方便理解还是分步赋值 (e.g.) b = a + 3, c = b
	int a = 20;
	int b = 50;
	int c = 30;

	c = c + 10; // 复合赋值, 与 c += 10 等价
	c++; // 等价于 c = c + 1
	c += 2; // 等价于 c = c + 2
	printf("c = %d", c);

	printf("%d\n", a * b);
	printf("%d\n", a / b); // /两端如果均为整数则运算结果只取至整数位
	printf("%f\n", 20.0 / 10); // /两端至少有一个浮点数方可得到小数部分的运算结果
	printf("%d\n", 6 % 4); // %:求模(余)运算(只能用于整数计算, 不可用于浮点数)
	printf("%d\n", -5 % 3); // 负数求模结果由第一个运算数的正负号决定 
	printf("%d\n", 5 % -3);
	printf("%d\n", -5 % -3);

	// a-- 与 a++ 同理
	a = 5;
	b = a++; // a自增1(后置++) 顺序:b = a, a = a + 1
	printf("a = %d\n", a);
	printf("b = %d\n", b);

	// --a 与 ++a 同理
	a = 5;
	b = ++a; // a自增1(前置++) 顺序:a = a + 1, b = a
	printf("a = %d\n", a);
	printf("b = %d\n", b);

	int d = (int)3.14; // (类型):强制类型转换
	printf("%d\n", d);

	return 0;
}