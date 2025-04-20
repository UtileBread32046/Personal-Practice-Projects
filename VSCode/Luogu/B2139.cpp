#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
  int m, n;
  cin >> m >> n;
  vector <int> result;

  for (int i = m; i <= n; i++) {
    bool ok = false;
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
      string num = to_string(i);
      reverse(num.begin(), num.end());
      int re = stoi(num);
      int k = 2;
      bool ok2 = false;
      for (k = 2; k <= sqrt(re); k++) {
        if (re % k == 0) {
          ok2 = false;
          break;
        }
      }
      if (k > sqrt(re))
        ok2 = true;
      if (ok2) {
        result.push_back(i);
        result.push_back(re);
      }
    }
  }

  sort(result.begin(), result.end());
  auto position = unique(result.begin(), result.end());
  result.erase(position, result.end());
  int sum = 0;
  for (auto &x: result) {
    if (x <= n)
      sum++;
  }
  bool empty = true;
  for (int i = 0; i < (int)result.size(); i++) {
    if (result[i] == 1)
      continue;
    if (m <= result[i] && result[i] <= n) {
      cout << result[i];
      empty = false;
      if (i < sum -1)
      cout << ",";
    }
  }
  if (empty)
    cout << "No";
  cout << endl;
  return 0;
}