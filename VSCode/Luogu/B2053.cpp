#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  double a, b, c = 0.0;
  double delta = 0.0;
  double x1, x2 = 0.0;
  cin >> a >> b >> c;
  delta = b*b-4*a*c;
  cout.precision(5);
  cout << fixed;
  if (delta < 0)
    cout << "No answer!";
  else if (delta == 0)
  {  
    x1 = x2 = (-b+sqrt(delta))/(2*a);
    cout << "x1=x2=" << x1;
  }
  else
  {  
    x1 = (-b+sqrt(delta))/(2*a);
    x2 = (-b-sqrt(delta))/(2*a);
    if (x1 < x2)
      cout << "x1=" << x1 << ";" << "x2=" << x2;
    else
      cout << "x1=" << x2 << ";" << "x2=" << x1;
  }

  return 0;
}