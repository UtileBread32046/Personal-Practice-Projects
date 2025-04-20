#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  double x1, x2, x3, y1, y2, y3 = 0.0;
  double p, a, b, c = 0.0;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  // a = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
  // b = sqrt(pow(x2-x3,2)+pow(y2-y3,2));
  // c = sqrt(pow(x1-x3,2)+pow(y1-y3,2));
  a = hypot(x1-x2, y1-y2);
  b = hypot(x2-x3, y2-y3);
  c = hypot(x1-x3, y1-y3);
  // 海伦公式
  p = (a+b+c)/2.0;
  cout.precision(2);
  cout << fixed;
  cout << sqrt(p*(p-a)*(p-b)*(p-c));

  return 0;
}