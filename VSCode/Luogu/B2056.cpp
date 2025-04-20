#include <iostream>
using namespace std;

int main()
{
  int n = 0;
  double n2 = 0;
  int x = 0;
  long long sum = 0; // 注意变量的取值范围!
  cin >> n;
  n2 = n;
  for (; n>0; n--)
  {
    cin >> x;
    sum += x;
  }
  cout << sum << " ";
  cout.precision(5);
  cout << fixed;
  cout << sum/n2;

  return 0;
}