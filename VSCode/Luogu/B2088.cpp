#include <iostream>
using namespace std;

int main()
{
  double money[10] = {28.9, 32.7, 45.6, 78, 35, 86.2, 27.8, 43, 56, 65};
  double sum = 0.0;
  int num = 0;
  for (auto i: money)
  {
    cin >> num;
    sum += num * i;
  }
  cout.precision(1);
  cout << fixed;
  cout << sum;

  return 0;
}