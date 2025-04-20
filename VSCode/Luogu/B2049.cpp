#include <iostream>
#include <algorithm> // 引入算法头文件, 调用最大值比较max函数
using namespace std;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  // if (a>=b && a>=c)
  //   cout << a;
  // else if (b>a && b>=c)
  //   cout << b;
  // else
  //   cout << c;
  cout << max(max(a,b), c); // <algorithm>中的max函数, 进行两个数的大小比较, 通过嵌套可实现多个数求最大值

  return 0;
}