#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  int array[5][5];
  for (auto &x: array) {
    for (auto &y: x) {
      cin >> y;
    }
  }

  // 法一: 新建数组比较法法
  // int x_max[5] = {};
  // for (int i = 0; i < 5; i++) {
  //   for (int j = 0; j < 5; j++) {
  //     if (x_max[i] < array[i][j])
  //       x_max[i] = array[i][j];
  //   }
  // }

  // int y_min[5] = {100, 100, 100, 100, 100};
  // for (int j = 0; j < 5; j++) {
  //   for (int i = 0; i < 5; i++) {
  //     if (y_min[j] > array[i][j])
  //       y_min[j] = array[i][j];
  //   }
  // }

  // int judge = 0;
  // for (int x = 0; x < 5; x++) {
  //   for (int y = 0; y < 5; y++) {
  //     if (x_max[x] == y_min[y]) {
  //       cout << x+1 << " " << y+1 << " " << x_max[x];
  //       judge++;
  //     }
  //   }
  // }

  // if (judge == 0)
  //   cout << "not found";


  // 法二: 嵌套遍历法
  bool isFound = false;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      bool isMax = true;
      bool isMin = true;
      // 设置新变量k直接遍历当前行中的所有元素并依次与当前选定的行中的第某列元素进行比较, 从而比较出该行的最大值
      for (int k = 0; k < 5; k++) {
        if (array[i][k] > array[i][j]) {
          isMax = false;
          break; // 优化算法: 在判断时只要存在一项不是较大者, 及意味着当前选定的第i行第j列元素不是该行的最大值, 即可退出此元素作为行内最大值的判断
        }
      }
      // 重新定义变量k遍历当前列中的所有元素并依次与当前选定的列中第某行元素进行比较, 从而比较出该列的最小值
      for (int k = 0; k < 5; k++) {
        if (array[k][j] < array[i][j]) {
          isMin = false;
          break; // 优化算法: 在判断时只要存在一项不是较小者, 及意味着当前选定的第i行第j列元素不是该列的最小值, 即可退出此元素作为列内最小值的判断
        }
      }
      if (isMax && isMin) { // 判断两种情况是否同时为真, 此时的选定元素即为题干所需元素
        cout << i+1 << " " << j+1 << " " << array[i][j];
        isFound = true;
      }
    }
  }
  if (isFound == false)
    cout << "not found";

  return 0;
}