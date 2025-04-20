#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int arr[n][n];
  for (auto &x: arr) {
    for (auto &y: x)
      cin >> y;
  }

  for (int j = 0; j < n; j++) {
    for (int i = n-1; i >= 0; i--)
      cout << arr[i][j] << " ";
    cout << endl;
  }

  return 0;
}