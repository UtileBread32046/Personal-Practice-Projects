#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  double x, n = 0.0;
  cin >> x >> n;
  x = x*pow((1+0.001), n);
  cout.precision(4);
  cout << fixed;
  cout << x;

  return 0;
}