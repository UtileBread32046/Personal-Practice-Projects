#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int a, b, c = 0;
  int sum = 0;
  int d = 0;
  cin >> a >> b >> c;
  // if (a + b > c)
  //   sum++;
  // if (a + c > b)
  //   sum++;
  // if (b + c > a)
  //   sum++;
  // if (sum == 3)
  //   cout << 1;
  // else
  //   cout << 0;
  d = max(a, max(b,c)); // 寻找a, b, c三者中的最大值
  sum = a + b + c - d; // 计算剩下两个数的和
  cout << (sum > d) << endl; // 比较两边之和与第三边的大小关系, 并以布尔类型的真值输出

  return 0;
}