#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int arr[n][n] = {};

  int sum = 0; // 定义总数
  int direction = 0; // 定义方向
  int min = 0, max = n; // 定义最小和最大边界
  int i = min, j = min; // 定义起始位置
  while (sum < n*n) { // 此处不取等, 因为恰好结束时如果再次满足条件就会无限进行下去
    switch (direction%4) {
      case 0: // 向右
        for (; j < max; j++) {
          sum++;
          arr[i][j] = sum;
        }
        j--; // 退回到边界位置
        i++; // 进入下一阶段
        direction++;
        break;
      case 1: // 向下
        for (; i < max; i++) {
          sum++;
          arr[i][j] = sum;
        }
        i--;
        j--;
        max--; // 缩小上界
        direction++;
        break;
      case 2: // 向左
        for (; j >= min; j--) {
          sum++;
          arr[i][j] = sum;
        }
        j++;
        i--;
        min++; // 缩小下界
        direction++;
        break;
      case 3: // 向上
        for (; i >= min; i--) {
          sum++;
          arr[i][j] = sum;
        }
        i++;
        j++;
        direction++;
        break;
    }
  }

  for (auto &x: arr) {
    for (auto &y: x)
      cout << y << " ";
    cout << endl;
  }

  return 0;
}