#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  // 题目中n最大取到10000, 使用float, double类型都会超出有效范围, 所以需要一步一步进行除法运算
  // 不知道为什么好像如果直接乘10的n次方精度不够怎么乘都不行, 只能求一位再乘10进一位
  int a, b, n = 0;
  cin >> a >> b >> n;
  while (n--)
  {
    // 这两个算式相当于在算草纸上一步一步算除法的过程
    a %= b;
    a *= 10;
  }
  a /= b; // 恰好移动到所需要的那一位(此时已乘10为几十的二位数), 然后再求出最后的整数部分
  cout << a;

  return 0;
}