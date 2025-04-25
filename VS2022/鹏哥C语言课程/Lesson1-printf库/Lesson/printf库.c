// Ctrl+F5:开始执行(不调试); F5:开始调试

#include <stdio.h> // 使包含头文件stdio.h, 调用printf库 standard+input+output+head→stdio.h:标准输入输出头文件
#include <string.h> // 使包含头文件string.h, 调用strlen库

int arr[] = { 0 };
int main() // main后的()不可丢!!!; int:main函数结束后返回一个整数; main:主函数, 有且只能有一个
{
	printf("hello, world\n\0看不见我"); // \n:换行; ""里为字符串; 中间插入\0可终止字符串打印 newline
	printf("hello\tworld\n"); // \t:水平制表符(Tab键), 使输出内容整齐
	printf("%s\n", "a"); // %s:打印字符串(可省略) string:字符串
	printf("%c\n", 'a'); // %c:打印字符; ''里为字符 character:字符; 也可用ASCII码表中的97替换'a'
	printf("%d\n", 100); // %d:打印整数 decimal integer:十进制整型数
	printf("%f\n", 1.1); // %f(单精度浮点数) or %lf(双精度浮点数):打印浮点数(默认取小数点后6位) float:浮动
	printf("%1.1f\n", 2.5); // %m.nf:打印至少m个字符宽度(包括整数、小数点和小数部分的位数)，n位小数
	printf("%zd\n", strlen("lalala")); // %zd:打印size_t类型变量 string+length→strlen:字符串长度
	printf("\a"); // \a:转义字符, 触发警报 alarm
	printf("%c\n", '\130'); // 将\后3位数字(8进制)转化为10进制并以ASCII码值输出 1*8²+3*8+0*1=88→X
	printf("%c\n", '\x36'); // 将\x后2位数字(16进制)转化为10进制并以ASCII码值输出 3*16+6*1=54→6
	printf("%p\n", &arr[0]); // %p:打印地址, &为取地址符
	return 0; // 返回数字0
}