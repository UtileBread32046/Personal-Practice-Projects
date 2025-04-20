#include <iostream>
using namespace std;

int main()
{
  double r = 0.0;
  double pai = 3.14159;
  cin >> r;
  cout.precision(4);
  cout << fixed;
  cout << 2*r << " " << 2*pai*r << " " << pai*r*r;

  return 0;
}