#include <iostream>
using namespace std;

int main()
{ 
  // 注意A*B最大为25万, 超出int数据类型范围, 此处需用long long或unsigned int
  unsigned int a, b = 0;
  cin >> a >> b;
  if (a, b > 0 && a, b <= 50000)
    cout << a*b;

  return 0;
}