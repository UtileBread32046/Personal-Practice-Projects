#include <iostream>
#include <string>
#include <vector>
using namespace std;

// int transform(char c) {
//   if (c == 'S')
//     return 3;
//   else if (c == 'P')
//     return 2;
//   else if (c == 'R')
//     return 1;
// }
// // R > S, S > P, P > R
// int judge(int a, int b) {
//   if (a == b+1 || a==1&&b==3)
//     return 2;
//   else if (a == b)
//     return 1;
//   if (a == b-1 || a==3&&b==1)
//     return 0;
// }

// 法二
int judge(char a, char b) {
  if (a == b) return 1;
  if (a == 'R' && b == 'S') return 2;
  if (a == 'S' && b == 'P') return 2;
  if (a == 'P' && b == 'R') return 2;
  else return 0;
}

int main()
{
  int r = 0;
  cin >> r;
  string Sven;
  cin >> Sven;
  int n = 0;
  cin >> n;
  int sum1 = 0;
  int sum2 = 0;
  // int sum_max = 0;
  // vector <string> group;
  vector<string> players(n);
  
  // for (int i = 0; i < n; i++) {
  //   string friends;
  //   cin >> friends;
  //   group.push_back(friends);
  //   for (int k = 0; k < r; k++) {
  //     // sum1 += judge(transform(Sven[k]), transform(friends[k]));
  //     sum1 += judge(Sven[k], friends[k]);
  //   }
  // }
  // for (int i = 0; i < n; i++) {
  //   sum2 = 0;
  //   string max;
  //   for (int l = 0; l < group[i].length(); l++) {
  //     if (group[i][l] == 'S')
  //       max += 'R';
  //     else if (group[i][l] == 'P')
  //       max += 'S';
  //     else if (group[i][l] == 'R')
  //       max += 'P';
  //   }
  //   for (int m = 0; m < n; m++) {
  //     for (int k = 0; k < r; k++) {
  //       sum2 += judge(max[k], group[m][k]);
  //     }
  //   }
  //   if (sum_max < sum2)
  //     sum_max = sum2;
  // }

  // 法二
  string spr = "SPR";
  for (auto &player: players) cin >> player;
  for (int i = 0; i < r; i++) { // 以列数为最外层循环, 从而优化时间复杂度
    vector<int> scores(3); // 将石头剪刀布的得分分开存储
    for (auto &player: players) { // 依次讨论每一个朋友
      sum1 += judge(Sven[i], player[i]);
      for (int j = 0; j < 3; j++) { // 石头剪刀布分别尝试
        scores[j] += judge(spr[j], player[i]); // 依次判断与每个朋友在当前列下的对战得分
      }
    }
    sum2 += max(scores[0], max(scores[1], scores[2])); // 取每一列的最优解
  }

  cout << sum1 << endl << sum2;

  return 0;
}