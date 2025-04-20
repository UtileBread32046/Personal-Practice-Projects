#include <iostream>
using namespace std;

int main()
{
  double x, a, y, b = 0.0;
  double z = 0.0;
  cin >> x >> a >> y >> b;
  z = (b*y-a*x)/(b-a);
  cout.precision(2);
  cout << fixed;
  cout << z;

  return 0;
}