#include <iostream>
using namespace std;

int main()
{
  // 法一: 变量法

  // // 也可以使用取模方便计算: sum += a % 3;
  // int a, b, c, d, e;
  // int sum = 0;
  // cin >> a >> b >> c >> d >> e;
  // sum = sum + a - 3*(a/3);
  // a/=3;
  // e+=a; b+=a;

  // sum = sum + b - 3*(b/3);
  // b/=3;
  // a+=b; c+=b;

  // sum = sum + c - 3*(c/3);
  // c/=3;
  // b+=c; d+=c;

  // sum = sum + d - 3*(d/3);
  // d/=3;
  // c+=d; e+=d;

  // sum = sum + e - 3*(e/3);
  // e/=3;
  // d+=e; a+=e;

  // cout << a << " " << b << " " << c << " " << d << " " << e << endl;
  // cout << sum;


  // 法二: 数组法
  int child[5] = {};
  int separation = 0;
  int eat = 0;
  for (auto &i: child)
    cin >> i;
  // for (int i = 0; i <= 4; i++)
  // {
  //   separation = child[i] / 3;
  //   eat += child[i] % 3;
  //   child[i] = child[i] / 3;
  //   if (1<=i && i<=3)
  //   {    
  //     child[i-1] += separation;
  //     child[i+1] += separation;
  //   }
  //   if (i == 0)
  //   {
  //     child[1] += separation;
  //     child[4] += separation;
  //   }
  //   if (i == 4)
  //   {
  //     child[3] += separation;
  //     child[0] += separation;
  //   }
  // }
  for (int i = 0; i <= 4; i++)
  {
    separation = child[i] / 3;
    eat += child[i] % 3;
    child[i] = child[i] / 3;
    // 优化算法: 将[]内的i+1和i-1替换成[(i+1)+n]%n和[(i-1)+n]%n(其中n为数组元素总个数), \
    通过将表示位置的数值统一加上总个数的数值并取余, 从而实现循环提取数组元素时收尾相连
    child[(i+4)%5] += separation;
    child[(i+1)%5] += separation;
  }
  for (auto i: child)
    cout << i << " ";
  cout << endl << eat;

  return 0;
}