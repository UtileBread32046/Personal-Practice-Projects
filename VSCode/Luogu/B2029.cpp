#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  int h, r = 0;
  double S, V = 0.0;
  cin >> h >> r;
  S = 3.14*r*r;
  V = S*h*0.001;
  cout << ceil(20/V);

  return 0;
}