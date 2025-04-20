#include <iostream>
using namespace std;

int main()
{
  double F = 0.0;
  cin >> F;
  cout.precision(5);
  cout << fixed;
  cout << 5*(F-32)/9;

  return 0;
}