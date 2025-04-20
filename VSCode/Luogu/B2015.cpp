#include <iostream>
using namespace std;

int main()
{
  double r1, r2 = 0.0;
  cin >> r1 >> r2;
  cout.precision(2);
  cout << fixed;
  cout << 1/(1/r1+1/r2);

  return 0;
}