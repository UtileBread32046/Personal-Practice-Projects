#include <iostream>
#include <vector>
using namespace std;

int Fibonacci(int n) // 斐波那契数列递归函数
{
  vector <int> saved(n+1, -1); // 应注意此处动态数组的大小应当为n+1, 否则会超出最大范围
  if (n <= 2)
    return 1;
  // return Fibonacci(n-1) + Fibonacci(n-2); // 直接调用函数递归, 时间复杂度成指数形式增长
  if (saved[n] == -1)
    saved[n] = Fibonacci(n-1) + Fibonacci(n-2);
  return saved[n]; // 使用记忆化搜索减少时间复杂度(指数级 -> 线性级)
}

void Hanoi(int n, char F, char A, char T) // 汉诺塔问题
{
  // 如果只有一个盘子，直接将其从起始柱子移动到目标柱子
  if (n == 1) {
    printf("move %d from %c to %c\n", n, F, T);
    return;
  }
  Hanoi(n-1, F, T, A); // 将 n-1 个盘子从起始柱子移动到辅助柱子
  printf("move %d from %c to %c\n", n, F, T); // 将最后一个盘子从起始柱子移动到目标柱子
  Hanoi(n-1, A, F, T); // 将 n-1 个盘子从辅助柱子移动到目标柱子
}
int main()
{
  int n;
  cin >> n;
  cout << Fibonacci(n) << endl;
  cin >> n;
  Hanoi(n, 'A', 'B', 'C');

  return 0;
}