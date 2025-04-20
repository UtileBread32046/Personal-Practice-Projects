#include <iostream>
using namespace std;

int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
  int y, m, d;
  cin >> y >> m >> d;
  if (y%4 == 0 && y%100 != 0 || y%400 == 0) months[1]++;

  int sum = 0;
  for (int i = 0; i < m-1; i++) {
    sum += months[i];
  }
  sum += d;
  cout << sum << endl;

  return 0;
}