#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  double Xa, Ya, Xb, Yb, len = 0.0;
  cin >> Xa >> Ya >> Xb >> Yb;
  // len = sqrt(pow(Xa-Xb, 2)+pow(Ya-Yb, 2));
  len = hypot(Xa-Xb,Ya-Yb); // 勾股定理函数, 原理如上
  cout.precision(3);
  cout << fixed;
  cout << len;

  return 0;
}