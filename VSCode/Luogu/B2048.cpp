#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  int x = 0;
  int sum = 8;
  char c = 0;
  cin >> x >> c;
  if (x > 1000)
    sum += ceil((x-1000)/500.0)*4; // 此处需除以500.0, 直接除以500只会得到0而忽略小数
  if ((int)c == (int)'y')
    sum += 5;
  cout << sum;

  return 0;
}