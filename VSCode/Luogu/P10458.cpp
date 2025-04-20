#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void B(auto &arr, int x, int y, int size) {
  if (size == 1) { // 确定最小单元
    arr[x][y] = 1; // 这个操作可以直接进行达到最深层递归的效果, 不需要再通过循环改数值, 否则会出bug
    return;
  }

  int edge = size / 3; // 缩小递归范围
  B(arr, x, y, edge); // 左上角分块递归
  B(arr, x+2*edge, y, edge); // 右上角
  B(arr, x+edge, y+edge, edge); // 中心
  B(arr, x, y+2*edge, edge); // 左下角
  B(arr, x+2*edge, y+2*edge, edge); // 右下角
}

int main()
{
  int n;
  while (cin >> n) {
    if (n == -1) break;
    int size = pow(3, n-1);
    auto arr = vector(size, vector(size, 0));
    B(arr, 0, 0, size);
    for (auto &x: arr) {
      for (auto &y: x) {
        if (y == 0) cout << " ";
        else cout << "X";
      }
      cout << endl;
    }
    cout << "-" << endl;
  }

  return 0;
}