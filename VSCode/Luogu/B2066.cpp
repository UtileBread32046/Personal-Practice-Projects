#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  int n = 0;
  double x, y, p = 0;
  double d = 0;
  double sum_t = 0;
  cin >> n;
  for (; n>0; n--)
  {
    cin >> x >> y >> p;
    d = hypot(x, y); // 求原点与点(x, y)的距离
    sum_t += d/50*2 + 1.5*p; // 此处的sum_t不可取整求和, 否则误差极大!!!
  }
  cout << (int)ceil(sum_t); // 末尾处再进行取整

  return 0;
}