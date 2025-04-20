#include <iostream>
using namespace std;

int main()
{
  int a, b, c = 0;
  int x = 2;
  cin >> a >> b >> c;
  for (;;)
  {
    if (a%x != b%x)
      x++;
    else
    {
      if (b%x != c%x)
        x++;
      else
        break;
    }
  }
  cout << x;

  return 0;
}