#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (auto &x: arr)
    cin >> x;
  int x;
  cin >> x;
  for (size_t i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
    if (arr[i] == x) {
      cout << i+1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;

  return 0;
}