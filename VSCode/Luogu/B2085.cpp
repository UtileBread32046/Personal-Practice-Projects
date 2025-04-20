#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  int n = 0;
  int i, r = 2;
  int sum = 0;
  cin >> n;
  for (i = 2;; i++)
  {
    for (r = 2; r <= sqrt(i); r++)
    {
      if (i%r == 0)
        break;
    }
    if (r > sqrt(i))
      sum++;
    if (sum == n)
      break;
  }
  cout << i;

  return 0;
}