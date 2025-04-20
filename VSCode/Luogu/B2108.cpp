#include <iostream>
#include <string.h>
using namespace std;

int main()
{  
  int n, m = 0;
  cin >> n >> m;
  int A[n][m] = {};
  double B[n][m] = {};
  // memcpy(B, A, sizeof(A)); // memroy+copy=memcpy; <string.h>头文件中函数: memcpy(数组1, 数组2, 数组2长度): 将数组2中的内存复制到数组1中

  for (auto &x: A) {
    for (auto &y: x) {
      cin >> y;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 || i == n-1 || j == 0 || j == m-1)
        B[i][j] = A[i][j];
      else {
        B[i][j] = (A[i][j] + A[i-1][j] + A[i+1][j] + A[i][j-1] + A[i][j+1]) / 5.0;
      }
    }
  }

  cout.precision(0);
  cout << fixed;
  for (auto &x: B) {
    for (auto &y: x) {
      cout << y << " ";
    }
    cout << endl;
  }

  return 0;
}