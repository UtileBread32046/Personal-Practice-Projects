#include <iostream>
using namespace std;

int main()
{
  int a, b, c = 0;
  int sum = 0;
  cin >> a >> b >> c;
  sum = ((a>=60) ? sum+1 : sum);
  sum = ((b>=60) ? sum+1 : sum);
  sum = ((c>=60) ? sum+1 : sum);
  // if (sum == 2)
  //   cout << '1';
  // else
  //   cout << '0';
  cout << (sum == 2); // 进行判断直接输出布尔类型的量代表0或1(整形)

  return 0;
}