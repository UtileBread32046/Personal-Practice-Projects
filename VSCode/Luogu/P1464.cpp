#include <iostream>
#include <vector>
#include <format>
using namespace std;

// int w(int a, int b, int c) {
//   if (a <= 0 || b <= 0 || c <= 0)
//     return 1;
//   else if (a > 20 || b > 20 || c > 20)
//     return w(20, 20, 20);
//   else if (a < b && b < c)
//     return w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
//   else
//     return w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
// }

// 法二
int w(auto &saved, long long a, long long b, long long c) { // 其中使用auto简化写法
  if (a <= 0 || b <= 0 || c <= 0) return 1;
  if (a > 20 || b > 20 || c > 20) return w(saved, 20, 20, 20);
  int &memo = saved[a][b][c]; // 通过引用操作符&简化写法
  if (memo != -1) return memo; // 如果不等于-1, 说明已经计算并存储过, 直接返回存储结果
  if (a < b && b < c) return memo = w(saved, a, b, c-1) + w(saved, a, b-1, c-1) - w(saved, a, b-1, c);
  return memo = w(saved, a-1, b, c) + w(saved, a-1, b-1, c) + w(saved, a-1, b, c-1) - w(saved, a-1, b-1, c-1);
}

int main()
{
  auto saved = vector(21, vector(21, vector(21, -1))); // 定义三维数组(21*21*21)进行记忆化搜索
  long long a = 0, b = 0, c = 0; // 注意题目中提供的取值范围

  // 法一
  // cin >> a >> b >> c;
  // while (!(a == -1 && b == -1 && c == -1)) {
  //   // cin >> a >> b >> c;
  //   cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
  //   cin >> a >> b >> c;
  // }

  // 法二
  while (cin >> a >> b >> c) {
    if (a == -1 && b == -1 && c == -1) break;
    cout << format("w({}, {}, {}) = {}", a, b, c, w(saved, a, b, c)) << endl;
  }


  return 0;
}