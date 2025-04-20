#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void pardon(auto &matrix, int x, int y, int size) { // 传入vector类型的动态数组可以更方便地获取大小
  if (size == 1) return; // 当拆分至最小单元格时不进行操作
  int half = size / 2; // 将总边长对半拆分
  for (int i = x; i < x+half; i++) { // 以(x, y)为左上角的起始坐标
    for (int j = y; j < y+half; j++) {
      matrix[i][j] = 0; // 将左上角部分全部赋值为0
    }
  }
  // 传入half作为新的size, 递归调用时进一步进行平分
  pardon(matrix, x, y+half, half); // 左下角
  pardon(matrix, x+half, y, half); // 右上角
  pardon(matrix, x+half, y+half, half); // 右下角
}

int main()
{
  int n;
  cin >> n;
  int m = pow(2, n);
  auto matrix = vector(m, vector(m, 1)); // 创建二维数组
  pardon(matrix, 0, 0, m);

  for (auto &x: matrix) {
    for (auto &y: x)
      cout << y << " ";
    cout << endl;
  }

  return 0;
}