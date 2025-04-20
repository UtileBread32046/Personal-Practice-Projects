#include <iostream>
using namespace std;

int main()
{
  int n, m = 0;
  cin >> n >> m;
  int A[n][m] = {};
  int B[m][n] = {};

  for (auto &x: A) {
    for (auto &y: x) {
      cin >> y;
    }
  }

  int xb, yb = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      yb = (n-1)-i; // 旋转矩阵中某元素的纵坐标(此处从1开始数)为新矩阵中的列数(共n列)从右向左数第(i+1)个(i从0开始取)
      xb = j; // 旋转矩阵中某元素的横坐标(此处从1开始数)为原矩阵中从左向右数该元素所在的列数
      B[xb][yb] = A[i][j];
    }
  }

  for (auto &x: B) {
    for (auto &y: x) {
      cout << y << " ";
    }
    cout << endl;
  }

  return 0;
}