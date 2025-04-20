#include <iostream>
using namespace std;

int main()
{
  // 注意说明中的整数取值范围, 若此处使用int类型变量则会溢出, 所以必须使用long long
  long long a, b = 0;
  cin >> a >> b;
  cout << a + b;

  return 0;
}