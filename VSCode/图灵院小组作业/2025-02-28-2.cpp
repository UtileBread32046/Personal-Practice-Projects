#include <iostream>
using namespace std;

int main()
{
  int n, i, j;
  cin >> n >> i >> j;
  for (int k = 1; k <= n; k++)
    cout << "(" << i << "," << k << ") ";
  cout << endl;
  for (int k = 1; k <= n; k++)
    cout << "(" << k << "," << j << ") ";
  cout << endl;
  
  int diff = i-j;
  for (int k = 1; k <= n; k++) {
    int l = k-diff;
    if (1 <= l && l <= n)
      cout << "(" << k << "," << l << ") ";
  }
  cout << endl;

  int sum = i+j;
  for (int k = n; k >= 1; k--) {
    int l = sum-k;
    if (1 <= l && l <= n)
      cout << "(" << k << "," << l << ") ";
  }

  return 0;
}