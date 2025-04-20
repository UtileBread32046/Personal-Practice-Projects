#include <iostream>
#include <format>
using namespace std;

int main()
{
// 法一(最慢):循环存储余数并倒序输出（需对０开头的数字进行特殊讨论）
// int a = 0;
// int b = 0;
// cin >> a;
// if (a >= 100)
// {  
//   for (;a>0;)
//   {
//     b =  a % 10;
//     printf("%d", b);
//     a = a / 10;
//   }
// }
// else if (a >= 10)
//   cout << a % 10 << (a/10) % 10 << "0" ;
// else
//   cout << a << "00";

// 法二(较快):设定三个变量分别存储三位数字并倒序输出
//   int input = 0;
//   int a = 0;
//   int b = 0;
//   int c = 0;
//   cin >> input;
//   c = input % 10;
//   b = (input/10) % 10;
//   a = (input/100) % 10;
//   cout << c << b << a;


// 法三(最快):将输入的数字以字符型式存储并倒序输出
  char a, b, c;
  cin >> a >> b >> c;
  cout << c << b << a;

  return 0;
}