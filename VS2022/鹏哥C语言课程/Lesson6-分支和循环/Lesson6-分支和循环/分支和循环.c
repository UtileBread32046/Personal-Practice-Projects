#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> // 使包含数学头文件, 使用计算相关的库函数
#include <string.h> // 使包含字符串头文件, 使用strcmp函数
#include <time.h> // 使包含time头文件, 从而调用time函数
#include <stdlib.h> // 使包含标准库头文件, 可调用system, rand, srand等库函数执行系统命令; standard+library=stdlib
// system("shutdown -s -t 60"); // 调用系统指令使计算机在60秒后关机
// system("shutdown -a"); // 取消上述关机指令

// 定义函数不可放到main函数中
void menu() // 使用void自定义一个不返回具体值的函数
{
	printf("------------\n");
	printf("|  1.PLAY  |\n");
	printf("|          |\n");
	printf("|  2.EXIT  |\n");
	printf("------------\n");
}

int main()
{
	// if分支
	// if判断语句末尾不可加上;, 否则会执行空语句跳出判断
	// 默认情况下if和else后面只能跟一条语句, 多出来的语句会报错或不受判断条件控制, 若欲添加多条语句可使用{}
	// 当进行变量与常量的比较时, 将常量放置在==左边以防止少打=
	int judge = 0;
	printf("请输入一个数字(判断真假):");
	scanf("%d", &judge);
	if (0 == judge) // 如果(为真)则执行; ==:判断相等符号 !=:判断不相等符号; =:赋值, 无法比较大小和充当条件
		printf("判断为假\n");
	else // 否则
		printf("判断为真\n");

	// 判断正负奇偶小练
	int num = 0;
	printf("请输入一个整数(判断正负奇偶):");
	scanf("%d", &num);
	if (num == 0)
		printf("0为假\n一切非零数为真\n");
	else if (num > 0) // 嵌套(简化版); 所有的else if必须在末尾的else前面
		printf("%d为正数\n", num);
	else
		printf("%d为负数\n", num);
	if (num % 2 == 1) // 判断输入num值除以2的余数是否为1
		printf("%d为奇数\n", num);
	else
		printf("%d为偶数\n", num);


	// 判断年龄小练
	int age = 0;
	printf("您今年几岁了(防沉迷系统)?\n");
	scanf("%d", &age);
	if (age >= 18)
	// 使用{}控制多条语句:程序块(复合语句)
	{ 
		printf("您已成年\n");
		printf("恭喜您防沉迷已解除!\n");
	}
	else
	{
		printf("您未成年\n");
		printf("很遗憾您未能解除防沉迷限制\n");
	}


	// C语言中else会和距离最近的if进行匹配, 与缩进距离无关
	// 法一:上一条if后加上else;以执行空语句跳出判断
	// 法二:将第二层判断整体放入{}中(可不另加else)
	int a = 0;
	int b = 0;
	int c = 0;
	printf("请分别输入a, b, c的值:");
	scanf("%d%*c%d%*c%d", &a, &b, &c);
	if (a == 1)
	{
		if (b == 0)
		{
			printf("a=1且b=0\n");
		}
	} 
	else // 这里的else在默认情况下会与距离最近的if匹配(此处已用{}隔开无影响)
	{
		printf("a≠1\n");
	}

	// 关系运算符不宜连用, 如a < b < c等价于(a < b) < c, 若(a < b)为真则输出1与c进行比较
	if (a < b && b < c) // &&:并且(and)
	{
		printf("a<b<c\n");
	}

	// 条件操作符(三目操作符) exp1 ? exp2 : exp3:如果exp1为真, 则exp2进行计算, 反之exp3进行计算, 计算的结果是整个表达式的结果
	b = a > 5 ? 3 : -3;
	// 等价于
	/*if (a > 5)
	*     b = 3;
	* else
	*     b = -3;
	*/
	printf("a = %d\nb = %d\n", a, b);
	 
	// 逻辑操作符 !:取反, 改变单个表达式的真假; &&:与, 同真才为真; ||:或, 同假才为假
	// 短路求值: 在使用逻辑操作符时, 如果仅根据左操作数即可知道整个表达式的结果, 则不再进行右操作数的运算
	int number0 = 0;
	int number1 = 0;
	int number2 = 0;
	int number3 = 0;
	int number4 = 0;
	number0 = (++number1 && number2++ || ++number3 && number4++); // ++number1(先计算后赋值):先计算number1 = number1 + 1, 输出结果为1(判断为真) \
	继续运算number2++(先赋值后计算): number2 = number2 + 1, 输出结果为0(判断为假), 终止||前运算的进行 \
	继续进行||后的运算, 以此类推... \
	()内为逻辑判断, 整体的输出结果为真则number0 = 1, 反之number0 = 0
	printf("number0 = %d\nnumber1 = %d\nnumber2 = %d\nnumber3 = %d\nnumber4 = %d\n", number0, number1, number2, number3, number4);


	// switch:一种特殊形式的if...else结构, 用于判断条件有多个结果的情况, 把多个else if改成更易用, 可读性更好的形式
	// case/default执行完语句后根据实际需要加上break, 否则会无条件进行通过匹配以下的语句
	// 当有多种情况满足所需结果时, 可使用连续行的case并在最后一个判断后加上break以进行简略书写
	// 整除小练
	int n = 0;
	printf("请输入一个整数(判断是否可被3整除):");
	scanf("%d", &n);
	switch (n % 3) // ()内必须为整形表达式
	{
	case 0: // case后的值必须为整形常量表达式(包括字符类型)
		printf("%d可以被3整除\n", n);
		break;
	case 1:
		printf("%d不可以被3整除, 余数为1\n", n);
		break;
	default: // case匹配失败时执行(可用于判断输入值是否在可行范围内)(default和case语句没有顺序限制)
		printf("%d不可以被3整除, 余数为2\n", n);
		break;
	}


	// while循环
	// while与if语法类似, 执行多语句时需使用{}
	// while循环如果一直满足条件就会进入死循环(无休止循环)
	// while循环初始化与判断表达式相对分散
	// 数字倒序小练
	int reverse = 0;
	printf("请输入一个整数, 之后将对其进行倒序: ");
	scanf("%d", &reverse);
	while (reverse >= 1) // 此处()内可直接写reserve以判断其值是否为0
	{
		printf("%d", reverse % 10);
		reverse = reverse / 10;
	}
	printf("\n");


	// for循环
	// 执行多语句时同样需要{}
	// for(表达式1; 表达式2; 表达式3) 1:初始化表达式 2:判断表达式 3:调整
	// 若for循环的判断条件中一开始为假则永远不会进行循环
	// 寻找倍数小练
	int i = 0;
	int sum = 0;
	printf("1~100中3の倍数有:");
	for (i = 1; i <= 100; i++) // 先判断i在100以内而非直接判断是否是3的倍数以确保循环的正常进行
	// 为简化步骤也可将上面i初始化为3并每次+3, 即可省去下面的判断步骤	
	{
		if (i % 3 == 0) // 在循环内部进行倍数判断
		// 此处别忘了加{}!
		{
			printf("%d, ", i);
			sum += i;
		}
	}
	printf("这些数的总和为%d\n", sum);


	// do while循环
	// do while循环是先进行一次循环而后判断是否进行下一次的循环(循环体至少执行一次)
	i = 1;
	do
	{
		printf("%d ", i);
		i++;
	}
	while (i <= 10);
	printf("\n");

	// 判断位数小练
	int input = 0;
	int numRead = 0;
	sum = 0;
	for (;;)
	{
		printf("请输入一个正整数(判断位数):");
		numRead = scanf("%d", &input);
		if (numRead == 1 && input > 0) // 判断输入数字为整数并且为正(此处无法排除小数输入)
		{
			for (; input > 0; input = input / 10)
				sum++;
			printf("这个正整数是%d位数\n", sum);
			break;
		}
		else
		{
			printf("您输入的数字并不是正整数！\n");
			while (getchar() != '\n'); // 清除缓存区的字符, 防止代码进入死循环
		}
	}


	// break语句 
	// break用于永久跳出循环, 继续执行后续代码(一个break只能跳出一层for循环)
	i = 1;
	while (i <= 10)
	{
		if (i == 5)
			break; // 当满足条件时退出循环执行后续代码
		printf("%d ", i);
		i++;
	}
	printf("\n");

	for (i = 1; i <= 10; i++)
	{
		if (i == 5)
			break;
		printf("%d ", i);
	}
	printf("\n");

	i = 1;
	do
	{
		if (i == 5)
			break;
		printf("%d ", i);
		i++;
	} 
	while (i <= 10);
	printf("\n");


	// continue语句
	// continue用于跳过本次循环中continue后面的代码(在for循环和while循环中有差异)
	i = 0;
	while (i < 10) // 此处若写成i<=10则会在后续中通过i++打印出11, 所以因为i<10
	{
		i++; // 此处需调节i++顺序, 防止后续打印被跳过
		if (i == 5)
			continue; // 当满足条件时跳过下面的打印步骤重新开始循环
		printf("%d ", i);
	}
	printf("\n");

	for (i = 1; i <= 10; i++)
	{
		if (i == 5)
			continue;
		printf("%d ", i);
	}
	printf("\n");
	

	// 素数打印小练(试除法)
	int j = 2;
	int input_begin = 0;
	int input_over = 0;
	int count = 0;
	for (;;)
	{
		printf("请输入你想在哪个闭区间内寻找素数: \n");
		scanf("%d", &input_begin);
		scanf("%d", &input_over);
		if (input_begin <= input_over) // 判断输入的数字是否满足闭区间条件?
			break;
		else
		{
			printf("您输入的范围有问题!\n");
			while (getchar() != '\n'); // 清除缓存区的字符, 防止代码进入死循环
		}
	}
	for (i = input_begin; i <= input_over; i++) // 此处可通过初始化i为稍大的奇数并用i+=2来排除偶数项仅考虑奇数, 简化算法
	{
		if (i == 1)
			continue;
		/* 素数判断简化算法: 若存在m = a*b, 则a和b中至少有一个数字 < √m (通过此方法可极大减少运算量) */
		for (j = 2; j <= sqrt(i); j++) // 循环判断在1~√i的数中是否存在i的约数, 进而筛选出素数; 基础方法可直接比较i与j的大小关系
		// sqrt(): 计算平方根函数 square root: 平方根, 二次根
		{
			if (i % j == 0)
				break;
		}
		if (j > sqrt(i)) // 素数判断可能在j>sqrt(i)之前提前结束(循环是因为j>√i才结束而不是因为找到了约数才结束, 则同样可以确定此时的i为素数), 所以需要进一步判断两者的大小关系
		{
			printf("%d ", i);
			count++;
		}
	}
	if (count == 0)
		printf("无");
	printf("\n你选取的范围内共有%d个素数。", count);
	printf("\n");


	// goto语句
	// goto语句可实现在同一个函数内跳转到设置好的标号处, 适用于在多层循环代码中快速跳出, 但使用不当会打乱程序的执行流程, 甚至出现死循环(尽量不用)
	/* (e.g.) 此处需使用3个break才可跳出3层循环嵌套(一个break只能跳出一层for循环), 但使用goto就可快速跳出
	for (...)
	{
		for (...)
		{
			for (...)
				{
					if (disaster)
						goto error;
				}
		}
	}
	error:
		... */


	// 字符串比较小练
	// 在进行两个字符串的比较时不能用==, 应用strcmp函数; string+compare=strcmp
	char string_input[100] = { 0 };
	again:
	printf("原来你也玩???");
	scanf("%s", string_input);
	if (strcmp("原神", string_input) == 0) // strcmp( , )中判断相等时输出数值为0
		printf("%s, 启动!", string_input);
	else
	{
		printf("回答错误!\n");
		goto again; // 此处也可用死循环直接编写程序, 不建议用goto语句
	}
	printf("\n");


	// rand():伪随机数生成函数(需包含<stdlib.h>头文件), ()不需要添加参数; random:随机的
	// rand函数生成的随机数范围为0~RAND_MAX(一般情况下为32767)
	// rand函数是对称为"种子"的基准值进行运算生成的伪随机数, 而默认种子为1, 所以直接调用多次重复结果都不会发生变化
	// srand():随机数生成种子设置函数 seed+random=srand; srand函数()内需要unsigned int类型的参数, ()内默认数字为1
	// Unix时间戳: 从1970年1月1日至今所经过的秒数(不考虑闰秒)
	// time(timer):时间获取函数(需包含<time.h>头文件), 当timer是空指针NULL时返回一个Unix时间戳
	// time函数返回类型是time_t类型(本质上为32或64位的整型变量)
	// 猜数字小练
	int num_random = 0;
	int num_guess = 0;
	int times = 1;
	GuessAgain: // 重新游玩
	srand((unsigned int)time(NULL)); // 此处通过time函数获取时间戳, 同时将time_t类型的参数强制转化为srand函数所需要的unsigned int类型并进行赋值, 从而获得一个时刻改变的种子以进行伪随机数的生成
	num_random = rand() % 100 + 1; // 通过将rand()生成的伪随机数除以100求余以得到0~99之间的伪随机数(可再添加后续运算以修改具体范围)
	printf("欢迎来到猜数字小游戏, 这里从1~100中任意挑选了一个数, 请尝试在7次以内猜出它: ");
	scanf("%d", &num_guess);
	for (;;)
	{
		if (times >= 7)
		{
			printf("未能在7次之内猜对, 游戏失败!\n");
			printf("正确答案是: %d\n", num_random);
			break;
		}
		if (num_guess > num_random)
		{
			while (getchar() != '\n');
			printf("很遗憾你猜错了, 提示: 猜大了!\n");
			printf("请再次尝试(剩余次数:%d次): ", 7 - times);
			scanf("%d", &num_guess);
			times++;
			// 此处while循环和printf函数所在行不宜交换顺序, 若while循环在下, 则会在打印完后完成while循环并再次进入for循环而重复打印一次 \
			而当while循环在上时, 进入下次循环后不会直接进行打印
		}
		else if (num_guess < num_random)
		{
			while (getchar() != '\n');
			printf("很遗憾你猜错了, 提示: 猜小了!\n");
			printf("请再次尝试(剩余次数:%d次): ", 7 - times);
			scanf("%d", &num_guess);
			times++;
		}
		else
		{
			printf("恭喜你答对了!\n");
			break;
		}
	}
	times = 1; // 重置猜测次数

	int guess_again = 0;
	menu(); // 调用前面定义的menu函数
	printf("再来一局请按1, 退出游戏请按2: ");
	scanf("%d", &guess_again);
	for (;;)
	{
		switch (guess_again)
		{
		case 1:
			goto GuessAgain;
			break;
		case 2:
			printf("游戏已退出!\n");
			return 0; // return函数:结束函数执行
		default:
			printf("未查询到该菜单, 请重新选择: ");
			scanf("%d", &guess_again);
			break;
		}
	}


	return 0;
}