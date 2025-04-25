#include <stdio.h>
#include <stdbool.h> // 使包含布尔头文件; 布尔类型:判断真假的一种数据类型

// {}外创建的变量称为 全局变量 g_:global
int g_num = 100; // 全局变量若不进行初始化则默认为0(局部变量不同)

// {}内创建的变量称为 局部变量(局部优先)
int main()
{
	_Bool TorF = false; // 定义布尔类型变量; 取值为false(0)或true(1); 0表示假, 一切非0表示真
	bool TorF2 = true; // 定义布尔类型变量の另一种写法

	if (TorF)
	{
		printf("判断为真\n");
	}
	else
	{
		printf("判断为假\n");;
	}

	printf("%zd\n", sizeof(char)); // sizeof():计算类型长度(单位:字节Byte)并返回一个整型值 1Byte=8bit (1个2进制位的存储需要一个bit比特位の空间0
	
	int a = 10;
	// sizeof的计算结果为size_t类型, 需要用%zd的形式进行打印
	// sizeof计算表达式长度时可省略(), 该表达式不会进行实际运算, 即不影响最终结果输出
	printf("%zd\n", sizeof a);
	
	signed int num1 = -100; // signed:有符号(-负号); signed int=int: 变量为可正可负的整数或0
	unsigned int num2 = 100; // unsigned:无符号(-负号); unsigned int=unsigned: 变量为非负整数
	printf("%d ", num1); // 打印signed int须使用%d
	printf("%u", num2); // 打印unsigned int须使用%u

	int age = 18; // 初始化:创建变量并赋予一个初值 (p.s.)在创建变量时进行初始化是一种好的编程习惯, 如果不进行初始化, 有的编译器会报错
	age = 20; // 赋值:将变量的当前值替换成新值
	char ch = 'a';
	float score = 3.14f; // 末尾添加f以确保为float类型
	double weight = 4.5;
	bool flag = true;
	return 0;
}