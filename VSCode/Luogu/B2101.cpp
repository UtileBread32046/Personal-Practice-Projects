#include <iostream>
using namespace std;

int main()
{
  int m, n = 0;
  int sum = 0;
  cin >> m >> n;
  int array[m][n];
  // 二维数组的for循环初始化法
  // 如果此处不使用auto则需要使用一个类型为int的数组[]
  for (auto &x: array) // 读取行数据(向量)
  {
    for (auto &y :x) // 读取行数据中的列数据(元素)
      cin >> y;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0 || j == 0 || i == m-1 || j == n-1) // 通过if判断来提取边缘元素
      sum += array[i][j]; // 通过上面if判断不会出现重复加和的情况
    }
  }
  cout << sum;
  

  return 0;
}