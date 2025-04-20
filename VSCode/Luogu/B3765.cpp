#include <iostream>
#include <vector>
using namespace std;

int main()
{
  // 法一
  // int N = 0;
  // cin >> N;
  // vector <vector <int> > web_sum(N);
  // vector <int> result;
  // result.push_back(1);

  // for (int i = 0; i < N; i++) {
  //   int T = 0;
  //   cin >> T;
  //   while (T--) {
  //     int j = 0;
  //     cin >> j;
  //     auto &x = web_sum[i];
  //     x.push_back(j);
  //   }
  // }

  // bool repeat = false;
  // auto &web = web_sum[0];
  // for (auto &x: web) {
  //   repeat = false;
  //   for (auto &m: result) {
  //     if (m == x) {
  //       repeat = true;
  //       break;
  //     }
  //   }
  //   if (repeat == false)
  //     result.push_back(x);
  //   repeat = false;
  //   for (auto &y: web_sum[x-1]) {
  //     for (auto &z: result) {
  //       if (y == z) {
  //         repeat = true;
  //         break;
  //       }
  //     }
  //     if (repeat == false)
  //       result.push_back(y);
  //     repeat = false;
  //   }
  // }

  // cout << result.size();

  // 法二
  int N = 0;
  cin >> N;
  vector <vector <int> > web_sum(N);

  for (auto &web: web_sum) {
    int T = 0;
    cin >> T;
    web.resize(T);
    for (auto &x: web)
      cin >> x;
  }
  web_sum.insert(web_sum.begin(), vector <int> ());

  vector <int> visited (N+1);
  visited[1] = true;
  for (auto &web: web_sum[1]) {
    visited[web] = true;
    for (auto &web_2: web_sum[web])
      visited[web_2] = true;
  }

  int sum = 0;
  for (auto &x: visited)
    sum += x;
  cout << sum;

  return 0;
}