#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &x: arr)
    cin >> x;
  reverse(arr.begin(), arr.end());
  for (auto &x: arr)
    cout << x << " ";
  cout << endl;

  return 0;
}