#include <iostream>
using namespace std;

int main()
{
  float x, y = 0.0;
  cin >> x;
  cout.precision(3);
  cout << fixed;
  if (0<=x && x<5)
    cout << -x+2.5;
  if (5<=x && x<10)
    cout << 2-1.5*(x-3)*(x-3);
  if (10<=x && x<20)
    cout << x/2 - 1.5;

  return 0;
}