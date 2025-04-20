#include <iostream>
using namespace std;

int main()
{
  long long m = 0;
  int k = 0;
  int sum = 0;
  cin >> m >> k;
  while (k>0)
  {
    if (k % 3 == 0)
      sum++;
    k /= 10;
  }
  if (sum == k)
    cout << "YES";
  else
    cout << "NO";

  return 0;
}