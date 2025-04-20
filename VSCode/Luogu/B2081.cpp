#include <iostream>
using namespace std;

int main()
{
  int n = 0;
  int sum = 0;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    if (i%7 != 0)
    {
      if (i%10 != 7 && i/10 != 7)
      {
        sum += i*i;
      }
    }
  }
  cout << sum;

  return 0;
}