#include <iostream>
using namespace std;

int num(int n) {
  if (n-10 >= 0)
    return 10;
  else if (n > 0)
    return n;
  else
    return 0;
}

int main()
{
  int n;
  cin >> n;
  int sum = 0;
  sum += num(n)*6;
  n -= 10;
  sum += num(n)*2;
  n -= 10;
  sum += num(n);
  cout << sum << endl;

  return 0;
}