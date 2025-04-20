#include <iostream>
using namespace std;

int main()
{
  double m;
  int n;
  cin >> m >> n;
  double sum = 0.0;
  double temp = m;
  
  while (n>0, n--) {
    m /= 2*1.0;
    sum += m; // 单向路程
  }
  sum *= 2; // 双向路程
  sum += temp; // 加上第一段路程
  sum -= m; // 减去重复计算的部分
  cout.precision(2);
  cout << fixed;
  cout << m << endl << sum << endl;

  return 0;
}