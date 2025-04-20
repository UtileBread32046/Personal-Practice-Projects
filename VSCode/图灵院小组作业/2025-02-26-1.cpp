#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> arr;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    arr.push_back(a);
  }
  int judge;
  cin >> judge;
  int sum = 0;
  for (auto &x: arr) {
    if (x == judge)
      sum++;
  }
  cout << sum << endl;

  return 0;
}