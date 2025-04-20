#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int arr[5][5];
  for (auto &x: arr) {
    for (auto &y: x)
      cin >> y;
  }
  int m, n;
  cin >> m >> n;
  for (int i = 0; i < 5; i++) {
    swap(arr[m-1][i], arr[n-1][i]);
  }

  for (auto &x: arr) {
    for (auto &y: x)
      cout << y << " ";
    cout << endl;
  }

  return 0;
}