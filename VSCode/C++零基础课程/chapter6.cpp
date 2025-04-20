#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

int main()
{
  // 字符串の初始化 (字符串=带有终止字符的字符数组)
  char str[] = {'a', 'b', 'c', 'd', '\0'}; // 定义字符数组
  char str1[] = "abcd"; // 此种定义方法会在末尾自动加上\0终止符, 而上面一种方法则不会
  char str2[] = "abc\""; // 使用\进行转义以在定义的字符串中加入双引号字符
  char str3[] = "= one + two * (three / four)";
  char delimiter[] = "=+*/()"; // delimiter:定界符, 分隔符


  // 字符串の输入&输出
  // scanf和cin会在字符串末尾处默认添加\0, 所以输入n
  scanf("%s", str); // 数组本身即代表地址, 所以此处不需要添加&
  cin >> str;
  // getline(): 第一个参数是字符数组, 第二个参数是最大输入的字符个数
  cin.getline(str, 10); // 普通cin函数无法获取输入过程中出现的空格或换行后的字符, 使用.getline()可全部输入到字符串中去;
  // <stdio.h>中的fgets函数, 前两个函数与getline()中相同, 第三个参数代表从哪输入; stdin: 从终端输入
  // 尽量不使用gets函数, 因为其无法限制大小, 存在安全风险
  fgets(str, 10, stdin);

  
  // 字符串相关操作
  /* <string.h> */
  int len = strlen(str); // strlen(): 获取字符串的长度(以结束字符结尾的长度)
  strcpy(str1, str); // strcpy(): 将第二个字符串复制到第一个字符数组(需确保此字符数组有足够的长度可以容纳第二个字符串)(只会复制结束字符之前的内容)
  strcat(str2, str1); // strcat(): 将第二个字符串复制到第一个字符串的末尾(同样需确保第一个字符数组的长度足够容纳)
  int order = strcmp(str1, str2); // strcmp(): 比较两个字符串的字典序大小, 返回比较顺序(可以与0进行大小比较)
  char* c = strstr(str1, str2); // strstr(): 判断第一个字符串是否包含第二个字符串, 返回第一个字符串中首次出现第二个字符串的地址(类型是char*, 指针类型), 将结果c减去第一个字符串即个得到下标(c-str1); 找不到则会返回NULL(可等价于0)
  if (c) {/*此处可添加输出内容表示(不)包含*/} // 可通过返回值直接判断第一个字符串中是否包含第二个字符串
  char* token = strtok(str3, delimiter); // strtok(): 用于分隔字符串, 将第一个字符串以第二个字符串中出现的字符进行分隔; 找到第一个非分隔符的位置并返回地址(如果没有则返回NULL), 同时将这个地址后的第一个分隔符替换为终止符\0
  while (token) { // 将原字符串str3中的one, two, three, four提取出来
    cout << token << endl;
    token = strtok(NULL, delimiter); // strtok()可记录上一次分隔的位置, 再次调用时第一个参数只需传入NULL
  }
  char arr[5];
  char ch = 'a';
  memset(arr, ch, sizeof(arr)); // memset(): 设置内存(内存的单位长度和一个字符长度均为一个字节, 所以可看作是对字符的操作), 第一个参数是内存的起始地址, 第二个参数是设置的值(字符型)(范围:-128~127), 第三个参数是内存的长度, 代表内存中从这个字符数组开始, 对应长度的内存都赋值为第二个参数
  // memset()也可用来对int数组进行批量初始化, 但只能赋值0或-1(因为0和-1用有符号整数来表示), 其他数字会输出一个大整数(因为int占4个字节)
  memcpy(str1, str2, sizeof(str2)); // memcpy(): 将一段内存从一个位置复制到另一个位置, 第一个参数代表目的地址, 第二个参数代表被复制的地址, 第三个参数代表要复制的内存长度
  // 数组无法用等号=直接赋值, 所以可以使用memcpy()

  /* <stdlib.h> */
  // ASCII+to+int/long long/float→atoi/atoll/atof(其中atof返回的类型实际是double而不是float)
  // atox(): 将字符串转成对应类似的数值(字符串需要是合法的数值, 否则得到的结果是0)
  cout << atoi("123") << endl;
  cout << atoll("12345678901") << endl;
  cout << atof("3.14") << endl;
  cout << atof("1e-4") << endl;
  cout << atof("0x1p-2") << endl;
  cout << atof("abc") << endl;

  /* <ctype.h> */
  // isx(): 判断是否为x
  // isprint(); // 所有可打印字符
  // isspace(); // 空格
  // isgraph(); // 除空格外所有可打印字符
  // ispunct(); // 各种符号!"#$:;<=>?@[\]~{}| ; is+punctuation→ispunct
  // isalnum(); // 数字0~9, 小写字母a~z, 大写字母A~Z; is+alpha+number→isalnum
  // isdigit(); // 数字0~9
  // isalpha(); // 小写字母a~z, 大写字母A~Z
  // isupper(); // 大写字母A~Z
  // islower(); // 小写字母a~z
  // toupper(); // 将小写字母转化为大写字母
  // tolower(); // 将大写字母转化为小写字母

  return 0;
}