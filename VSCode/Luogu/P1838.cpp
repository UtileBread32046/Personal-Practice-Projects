#include <iostream>
#include <vector>
using namespace std;

bool isSame(int x, int a, int b, int c) {
  return a==x && b==x && c==x; // 直接在return中进行判断 
}
bool isWin(vector<vector<int>> &board, int x) {
  for (int i = 0; i < 3; i++) {
    if (isSame(x, board[i][0], board[i][1], board[i][2])) return true; // 判断行
    if (isSame(x, board[0][i], board[1][i], board[2][i])) return true; // 判断列
  }
  if (isSame(x, board[0][0], board[1][1], board[2][2])) return true; // 判断主对角线
  if (isSame(x, board[2][0], board[1][1], board[0][2])) return true; // 判断副对角线
  return false; // 都不成立时返回false
}

int main()
{
  // 法一
  // int positions[3][3] = {};
  // int num = 0;
  // num = getchar();
  // bool xiaoa_putting = true;
  // while (num != '\n') {
  //   int x, y = 0;
  //   x = (num-49) / 3;
  //   y = (num-49) % 3;
  //   if (xiaoa_putting) {
  //     positions[x][y] = 1;
  //     xiaoa_putting = false;
  //   }
  //   else {
  //     positions[x][y] = -1;
  //     xiaoa_putting = true;
  //   }
  //   num = getchar();
  // }

  // bool xiaoa_win = false, uim_win = false;
  // while (!xiaoa_win &&!uim_win) {
  //   int sum = 0;
  //   // 行
  //   for (int i = 0; i < 3; i++) {
  //     for (int j = 0; j < 3; j++)
  //       sum += positions[i][j];
  //     if (sum == 3)
  //       xiaoa_win = true;
  //     else if (sum == -3)
  //       uim_win = true;
  //     else
  //       sum = 0;
  //   }
  //   // 列
  //   for (int j = 0; j < 3; j++) {
  //     for (int i = 0; i < 3; i++)
  //       sum += positions[i][j];
  //     if (sum == 3)
  //       xiaoa_win = true;
  //     else if (sum == -3)
  //       uim_win = true;
  //     else
  //       sum = 0;
  //   }
  //   // 主对角线
  //   for (int i = 0; i < 3; i++)
  //     sum += positions[i][i];
  //   if (sum == 3)
  //     xiaoa_win = true;
  //   else if (sum == -3)
  //     uim_win = true;
  //   else
  //     sum = 0;
  //   // 副对角线
  //   for (int i = 0; i < 3; i++)
  //     sum += positions[2-i][i];
  //   if (sum == 3)
  //     xiaoa_win = true;
  //   else if (sum == -3)
  //     uim_win = true;
  //   else
  //     sum = 0;

  //   // for (auto &x: positions) {
  //   //   for (auto &y: x)
  //   //     cout << y << " ";
  //   //   cout << endl;
  //   // }
  //   break;
  // }

  // if (xiaoa_win)
  //   cout << "xiaoa wins.";
  // else if (uim_win)
  //   cout << "uim wins.";
  // else
  //   cout << "drew.";

  // 法二
  string str;
  cin >> str; // 直接以字符串形式存储
  auto board = vector(3, vector(3, -1)); // 初始化棋盘(均填上-1)
  for (size_t i = 0; i < str.size(); i++) {
    int pos = str[i] - '1'; // 将字符转化为下标数字
    int x = pos/3, y = pos%3; // 进行坐标转换(需要下标从0开始)(此时的下标为0~8而非1~9)
    // pos = x*3 + y; 通过x和y计算pos
    board[x][y] = i%2; // 通过0/1交替模拟双方下棋
  }
  // for (auto &x: board) {
  //   for (auto &y: x)
  //     cout << y << " ";
  //   cout << endl;
  // }
  if (isWin(board, 0)) cout << "xiaoa wins." << endl;
  else if (isWin(board, 1)) cout << "uim wins." << endl;
  else cout << "drew." << endl;

  return 0;
}