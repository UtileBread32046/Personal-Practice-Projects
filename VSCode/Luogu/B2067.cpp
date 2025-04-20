#include <iostream>
using namespace std;

int main()
{
  int m, n, x = 0;
  int sum = 0;
  cin >> m >> n;
  for (int times = 1; times<=n; times++)
  {
    cin >> x;
    if (m-x >= 0)
      m -= x;
    else
      sum++; // 此处必须在else分支下进行计数, 如果在if分支下对n进行递减, 则会干扰循环次数!!!
  }
  cout << sum;

  return 0;
}