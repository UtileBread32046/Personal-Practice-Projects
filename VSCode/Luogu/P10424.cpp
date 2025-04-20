#include <iostream>
using namespace std;

// 法一
// bool judge(int N)
// {
//   int i = 0;
//   while (N > 0) {
//     i++;
//     if (i%2 != 0) {
//       if (N%2 != 0) {
//         N /= 10;
//         continue;
//       }
//       else
//         return false;
//     }
//     else {
//       if (N%2 == 0) {
//         N /= 10;
//         continue;
//       }
//       else
//         return false;
//     }
//   }

//   return true;
// }

// 法二
bool judge(int x) {
  for (int i = 1; x; i++, x/=10) { // 同时对位数和原正整数进行操作
    if (x%10%2 != i%2) return  false; // 直接判断取模是否相等
  }
  return true;
}

int main()
{
  int n = 0;
  cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    // if (judge(i))
    //   sum++;
    sum += judge(i); // 布尔值通过隐式转化为int
  }
  cout << sum;

  return 0;
}