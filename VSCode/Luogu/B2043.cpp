#include <iostream>
using namespace std;

int main()
{
  int x = 0;
  cin >> x;
  if (x%3 == 0)
    cout << "3 ";
  if (x%5 == 0)
    cout << "5 ";
  if (x%7 == 0)
    cout << "7 ";
  // if(x%3!=0 && x%5!=0 && x%7!=0)
  if (x%3 && x%5 && x%7) // 计算各个余数, 只要都不为0就可判断为真
    cout << 'n';


  return 0;
}