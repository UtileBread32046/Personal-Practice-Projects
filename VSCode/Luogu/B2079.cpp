#include <iostream>
#include <numeric> // numeric: 数字的
using namespace std;

int main()
{
  // 法一: 变量法
  // int n = 0;
  // double e = 1.0;
  // double jie_cheng = 1.0;
  // cin >> n;
  // cout.precision(10);
  // cout << fixed;
  // for (int i = 1; i <= n; i++)
  // {
  //   for (int r = 1; r <= i; r++)
  //   {
  //     jie_cheng = jie_cheng * r;
  //   }
  //   e = e + 1/jie_cheng;
  //   jie_cheng = 1.0; // 每次加和后需重置阶乘从1开始重新运算
  // }
  // cout << e;

  // 法二: 数组法
  // 数组中可以使用数列中的递进思想来进行运算的简化
  double e[15] = {1};
  int n = 0;
  cin >> n;
  for (int i = 1; i < 15; i++)
    e[i] = e[i-1] / (i+1);
  cout.precision(10);
  cout << fixed;
  // 使用<numeric>头文件中的accumulate函数, 可对规定的数组起始位置进行加和
  cout << accumulate(e, e+n, 1.0); // accumulate(起点, 终点, 初始值) 其中初始值为加和后额外加上的数, 如果为整数则输出结果默认为int类型 \
  起点默认为第一项, 终点+n则代表从起点开始数加到第n个

  return 0;
}