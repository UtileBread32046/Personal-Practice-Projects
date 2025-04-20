#include <iostream>
#include <format>
using namespace std;

int main()
{
  // 9*9乘法表打印
  for (int a=1; a<=9; a++)
  {
    for (int b=1; b<=a; b++)
      cout << format("{}*{}={:<2} ", a, b, a*b); // {:<2}: 向左对齐2格
    cout << endl;
  }

  return 0;
}