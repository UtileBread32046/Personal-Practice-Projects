#include <iostream>
using namespace std;

int main()
{
  double a, b, r = 0.0;
  int k = 0;
  cin >> a >> b;
  k = a/b;
  r = a-k*b;
  cout << r;

  return 0;
}