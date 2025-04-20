#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int n, g = 0;
  int m = 0;
  cin >> n;
  for (; n>0; n--)
  {
    cin >> g;
    m = max(m, g);
  }
  cout << m;

  return 0;
}