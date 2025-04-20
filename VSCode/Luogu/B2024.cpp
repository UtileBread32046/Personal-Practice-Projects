#include <iostream>
#include <format>
using namespace std;

int main()
{
  double d = 0.0;
  scanf("%lf", &d);
  printf("%f\n%.5f\n%e\n%g", d, d, d, d);

  return 0;
}