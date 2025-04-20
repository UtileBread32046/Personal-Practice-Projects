#include <iostream>
#include <vector>
using namespace std;

int main()
{
  // 初始化
  int n, m, r = 0;
  cin >> n >> m >> r;
  vector <int> f1(n), p1(n), f2(n), p2(n);
  for (auto &i: f1) cin >> i;
  for (auto &i: p1) cin >> i;
  for (auto &i: f2) cin >> i;
  for (auto &i: p2) cin >> i;

  // 算法
  while (n--) {
    int p = 0;
    int last = -1;
    cin >> p;
    for (int i = 0; i < (int)f2.size(); i++) {
      if (f2[i] == f1[p-1] && p2[i] > p1[p-1]) {
        if (last == -1 || p2[i] < p2[last]) {
          last = i;
        }
      }
    }
    if (last != -1) {
      f2.erase(f2.begin()+last);
      p2.erase(p2.begin()+last);
    }
  }

  cout << f2.size();

  return 0;
}