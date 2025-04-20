#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  int l;
  cin >> l;
  int sum = 0;
  int num = 0;
  for (int i = 2; i <= l; i++) {
    bool ok = true;
    int j = 2;
    for (j = 2; j <= sqrt(i); j++) {
      if (i % j == 0) {
        ok = false;
        break;
      }
    }
    if (j > sqrt(i))
      ok = true;
    if (ok) {
      sum += i;
      if (sum > l)
        break;
      cout << i << endl;
      num++;
    }
  }
  cout << num;

  return 0;
}