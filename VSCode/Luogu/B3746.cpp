#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n, m = 0;
  cin >> n >> m;
  vector <vector <int> > result(n);
  vector <long long> time_sum(n);

  for (int index = 1; index <= m; index++) {
    int x = 0;
    cin >> x;
    int candidate = 0;
    for (int i = 1; i < n; i++) {
      if (time_sum[i] < time_sum[candidate])
        candidate = i;
    }
    time_sum[candidate] += x;
    result[candidate].push_back(index);
  }

  for (auto &x: result) {
    if (x.size() == 0)
      cout << 0 << endl;
    else {
      for (auto &y: x)
        cout << y << " ";
      cout << endl;
    }
  }

  return 0;
}