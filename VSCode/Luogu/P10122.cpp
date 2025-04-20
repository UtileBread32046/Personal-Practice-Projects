// 个人做的只有50分
// #include <iostream>
// using namespace std;

// // 存储两种结果
// struct Result {
//   int single = 0;
//   int group = 0;  
// } result;

// // 判断单独
// bool judge_single(char A, char B, char C) {
//   if (A==B && B==C)
//     return true;
//   return false;
// }
// // 判断成组
// bool judge_group(char A, char B, char C) {
//   if (A==B&&A!=C || A==C&&B!=C || B==C&&A!=B)
//     return true;
//   return false;
// }

// // 判断行
// // bool hang(char arr[3][3]) {
// void hang(char arr[3][3]) {
//   for (int i = 0; i < 3; i++) {
//     if (judge_single(arr[i][0], arr[i][1], arr[i][2])) {
//       result.single++;
//       // break;
//     }
//   }
//   for (int i = 0; i < 3; i++) {
//     if (judge_group(arr[i][0], arr[i][1], arr[i][2])) {
//       result.group++;
//       // return true;
//       // break;
//     }
//   }
//   // return false;
// }
// // 判断列
// // bool lie(char arr[3][3]) {
// void lie(char arr[3][3]) {
//   for (int j = 0; j < 3; j++) {
//     if (judge_single(arr[0][j], arr[1][j], arr[2][j])) {
//       result.single++;
//       // break;
//     }
//   }
//   for (int j = 0; j < 3; j++) {
//     if (judge_group(arr[0][j], arr[1][j], arr[2][j])) {
//       result.group++;
//       // return true;
//       // break;
//     }
//   }
//   // return false;
// }
// // 判断对角线
// void dui(char arr[3][3]) {
//   if (judge_single(arr[0][0], arr[1][1], arr[2][2]) || judge_single(arr[0][2], arr[1][1], arr[2][0]))
//     result.single++;
//   if (judge_group(arr[0][0], arr[1][1], arr[2][2]) || judge_group(arr[0][2], arr[1][1], arr[2][0]))
//     result.group++;
// }

// int main()
// {
//   char arr[3][3];
//   for (auto &x: arr) {
//     for (auto &y: x)
//       cin >> y;
//   }

//   // hang(arr);
//   // if (!hang(arr)) {
//   //   lie(arr);
//   //   if (!lie(arr)) {
//   //     dui(arr);
//   //   }
//   // }
//   hang(arr);
//   lie(arr);
//   dui(arr);
//   cout << result.single << endl << result.group;

//   // for (auto &x: arr) {
//   //   for (auto &y: x)
//   //     cout << y << " ";
//   //   cout << endl;
//   // }

//   return 0;
// }


// 法二
#include <iostream>
#include <vector>
using namespace std;

bool isSame(int x, int y, int a, int b, int c) { // 多引入一个y防止重复计算
  if (x == y) return a == x && b == x && c == x; // 自己和自己组队(单独情况)
  int cnt1 = (x == a) + (x == b) + (x == c); // 得到x出现次数
  int cnt2 = (y == a) + (y == b) + (y == c); // 得到y出现次数
  return (cnt1 + cnt2 == 3) && (cnt1 != 3 && cnt2 != 3); // 保证只含有x, y的同时防止单独胜利的情况也计入组队胜利中
}

bool isWin(vector<string> &board, int x, int y) {
  for (int i = 0; i < 3; i++) {
    if (isSame(x, y, board[i][0], board[i][1], board[i][2])) return true;
    if (isSame(x, y, board[0][i], board[1][i], board[2][i])) return true;
  }
  if (isSame(x, y, board[0][0], board[1][1], board[2][2])) return true;
  if (isSame(x, y, board[2][0], board[1][1], board[0][2])) return true;
  return false;
}

int main()
{
  vector<string> board(3);
  for (auto &line: board) cin >> line;
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < 26; i++) { // 从0~26进行枚举
    if (isWin(board, i+'A', i+'A')) cnt1++; // 只有两种(和自己组队)
    for (int j = 0; j < i; j++) {
      if (isWin(board, i+'A', j+'A')) cnt2++;
    }
  }
  cout << cnt1 << endl << cnt2 << endl;

  return 0;
}

// 法三(deepseek)
// #include <iostream>
// #include <set>
// #include <vector>
// #include <utility>
// using namespace std;

// int main() {
//     char grid[3][3];
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             cin >> grid[i][j];
//         }
//     }

//     set<char> single_winners;
//     set<pair<char, char>> team_winners;

//     // 定义所有可能的线（行、列、对角线）
//     vector<vector<pair<int, int>>> lines = {
//         // 行
//         {{0,0}, {0,1}, {0,2}},
//         {{1,0}, {1,1}, {1,2}},
//         {{2,0}, {2,1}, {2,2}},
//         // 列
//         {{0,0}, {1,0}, {2,0}},
//         {{0,1}, {1,1}, {2,1}},
//         {{0,2}, {1,2}, {2,2}},
//         // 对角线
//         {{0,0}, {1,1}, {2,2}},
//         {{0,2}, {1,1}, {2,0}}
//     };

//     for (const auto& line : lines) {
//         // 提取三个位置的字符
//         char a = grid[line[0].first][line[0].second];
//         char b = grid[line[1].first][line[1].second];
//         char c = grid[line[2].first][line[2].second];
        
//         set<char> chars = {a, b, c};
//         if (chars.size() == 1) {
//             single_winners.insert(a);
//         } else if (chars.size() == 2) {
//             // 确保有序，避免重复
//             char first = *chars.begin();
//             char second = *next(chars.begin());
//             team_winners.insert({first, second});
//         }
//     }

//     cout << single_winners.size() << endl;
//     cout << team_winners.size() << endl;

//     return 0;
// }