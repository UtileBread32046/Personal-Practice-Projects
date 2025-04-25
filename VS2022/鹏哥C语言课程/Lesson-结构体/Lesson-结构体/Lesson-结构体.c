#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stddef.h> // 引入offsetof()函数

// 结构是一些值的集合, 这些值称为成员变量. 结构的每个成员可以是不同类型的变量

// 结构体类型的声明
struct Book // 也可以放到main函数里进行声明
{
	char book_name[20];
	char author[20];
	float price; // 浮点数在内存中有可能无法精确保存(导致输出数值与预期不符)
	char id[19];
}b4, b5, b6; // 不可忽略此处的分号;!!!
// ↑↑↑结构体(全局)变量的创建(法二)(在括号}和分号;的中间定义变量名)

// 结构体的特殊声明(不完全声明)
struct // 匿名结构体(不定义结构体的名字)(只可使用一次)
{
	char c;
	int i;
	double d;
}s1, s2;

// 结构体的自引用
// 通过结构体和指针的结合设置链表
typedef struct Node // 对结构体类型重命名
{
	int data; // 数据域(存放数据)
	struct Node* next; // 指针域(存放地址); 此处绝不可去掉星号*, 否则结构体内存无法计算导致报错; 此处需使用结构体原名而非自定义命名
}Node; // 此处使用typedef关键字将struct Node简写为Node

// 结构体内存对齐
// 结构体的成员在内存中存在"对齐"现象, 一说是平台原因, 一说是性能原因(减少内存读取次数, 时间复杂度转化为空间复杂度)
// 为节省空间, 可让占用空间小的成员集中在一起
/* 对齐规则
   1.结构体的第一个成员对齐到和结构体变量起始位置偏移量为0的地址处
   2.其他成员变量要对齐到某个数字(对齐数)的整数倍的地址数; 对齐数 = min{编译器默认对齐数, 该成员变量大小}; VS中默认对齐数为8; Linux中gcc没有默认对齐数(即对齐数为成员自身大小)
   3.结构体总大小为最大对齐数(结构体中每个成员变量的对齐数中的最大值)的整数倍
   4.当存在结构体嵌套时, 嵌套的结构体成员对齐到自己的成员中最大对齐数的整数倍处, 结构体的整体大小就是所有最大对齐数(含嵌套结构体中成员的对齐数)的整数倍
*/
struct S1
{
	char c1; // 1
	char c2; // 1 -> 4
	int n; // 4
};
struct S2
{
	char c1; // 1 -> 4
	int n; // 4
	char c2; // 1 -> 4
};
struct S3
{
	double d; // 8
	char c; // 1 -> 4
	int i; // 4
};
struct S4
{
	char c1; // 1 -> 4
	struct S3 s3; // 16
	double d; // 8
};

// 修改默认对齐数
#pragma pack(1) // 将默认对齐数调整为1
struct S5
{
	char c1;
	int n;
	char c2;
};
#pragma pack() // 重置默认对齐数

struct S
{
	int arr[1000];
	int n;
	char ch;
};

void print1(struct S tmp)
{
	for (int i = 0; i < 10; i++)
		printf("%d ", tmp.arr[i]);
	printf("\n");
	printf("n = %d\n", tmp.n);
	printf("ch = %c\n", tmp.ch);
}

void print2(struct S* ps)
{
	for (int i = 0; i < 10; i++)
		printf("%d ", ps->arr[i]);
	printf("\n");
	printf("n = %d\n", ps->n);
	printf("ch = %c\n", ps->ch);
}

// 结构体实现位段
// 位: 二进制中的位; 可使用位段进一步节省空间
// 位段的声明与结构体类似, 但位段的成员必须是int, unsigned int, signed int(在C99中也可选择其他类型)), 且位段的成员名后有一个冒号和一个数字
// 位段的内存分配
// 位段的成员可以是int, unsigned int, signed int, char
// 位段的空间是按照需要以4个字节(int)或1个字节(char)的方式来开辟的
// int位段有没有符号不确定; 位段中最大位数目不确定; 位段成员在内存中的分配方向无标准; 位段成员无法被容纳于剩余位时, 剩余位利用或浪费不确定
// 位段可以达到与结构相同的效果, 并且可以很好地节省空间; 位段不跨平台, 注重可移植的程序应当避免使用位段; 位段可以应用在网络协议中, 有利于网络的畅通
// 位段使用的注意事项
// 位段的几个成员共用一个字节, 则有部分成员的起始位置不在该字节的起始位置, 即没有地址(字节有地址, 字节内部的bit位没有地址), 所以不可使用scanf( , &成员名)的方式直接给成员输入值, 必须先输入给一个变量再通过变量赋值给成员
struct A
{
	// _变量名 为一种习惯, 表示作为一个成员变量
	int _a : 2; // 占2个比特位
	int _b : 5;
	int _c : 10;
	int _d : 30; // 该数值不可超过32(整形变量4个字节最多占32个比特位)
};

int main()
{
	struct Book b1; // 结构体(局部)变量的创建(法一)
	struct Book b2 = {"鹏哥C语言", "鹏哥", 38.8f, "PG20240520"}; // 结构体变量的初始化(顺序)
	struct Book b3 = {.id="DG20240520", .book_name="蛋哥Linux", .author="蛋哥", .price=55.5f}; // 结构体变量的初始化(乱序):.成员名=
	struct S4 s4;
	printf("%s %s %f %s\n", b2.book_name, b2.author, b2.price, b2.id);
	printf("%s %s %f %s\n", b3.book_name, b3.author, b3.price, b3.id);
	printf("\n");

	// offsetof: C语言中的一种宏(一种预定义的代码片段, 可以在程序中进行替换, 提供一种方便的方式来定义一些常量或进行一些简单的代码替换操作)
	// 计算结构体成员相交于结构体变量起始位置的偏移量
	printf("%zd ", offsetof(struct S1, c1));
	printf("%zd ", offsetof(struct S1, c2));
	printf("%zd ", offsetof(struct S1, n));
	printf("sum = %zd\n", sizeof(struct S1));

	printf("%zd ", offsetof(struct S2, c1));
	printf("%zd ", offsetof(struct S2, n));
	printf("%zd ", offsetof(struct S2, c2));
	printf("sum = %zd\n", sizeof(struct S2));

	printf("%zd ", offsetof(struct S3, d));
	printf("%zd ", offsetof(struct S3, c));
	printf("%zd ", offsetof(struct S3, i));
	printf("sum = %zd\n", sizeof(struct S3));

	printf("%zd ", offsetof(struct S4, c1));
	printf("%zd ", offsetof(struct S4, s3));
	printf("%zd ", offsetof(struct S4, d));
	printf("sum = %zd\n", sizeof(struct S4));

	printf("%zd ", offsetof(struct S5, c1));
	printf("%zd ", offsetof(struct S5, n));
	printf("%zd ", offsetof(struct S5, c2));
	printf("sum = %zd\n", sizeof(struct S5));
	printf("\n");

	// 结构体传参
	struct S s = { {1,2,3,4,5,6,7,8,9,10}, 10, 'w' };
	print1(s); // 传值调用; 会再次创建一个内存大小一样的结构体, 消耗空间; 函数传参时参数需要压栈, 有时间和空间上的系统开销, 导致性能下降
	print2(&s); // 传递地址, 消耗空间少; 所以结构体传参时, 要传递结构体的地址(并且传递地址可以修改原数据(可用const保护指针指向的内容, 防止修改数据), 而仅传值不可以)
	printf("\n");

	printf("%zd\n", sizeof(struct A));


	return 0;
}