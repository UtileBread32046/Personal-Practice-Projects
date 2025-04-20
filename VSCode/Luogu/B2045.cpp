#include <iostream>
using namespace std;

int main()
{
  int a = 0;
  cin >> a;
  // cout << ((a!=1 && a!=3 && a!=5) ? "YES" : "NO");
  cout << ((a%2 && a!=7) ? "NO" : "YES"); // 先计算a的奇偶, 用余数代表真假进行逻辑判断

  return 0;
}