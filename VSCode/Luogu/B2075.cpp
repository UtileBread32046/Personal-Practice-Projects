#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  int a, b = 0;
  int c = 0;
  int sq = 1;
  cin >> a >> b;
  for (int i = 1; i <= b; i++)
  {
    sq = sq*a; // 此处应注意不可直接写a = a*a, 因为每一次循环a都将会改变而不是单纯的b个a相乘!
    sq = sq % 1000;
  }
  // c = sq;
  // if (c < 100)
  // {
  //   if (c < 10)
  //   {
  //     if (c > 0)
  //       cout << 0 << 0 << c;
  //     else
  //       cout << c+1000;
  //   }
  //   else
  //     cout << 0 << c;
  // }
  // else
  //   cout << c;
  cout.width(3);
  cout.fill('0');
  cout << sq;


  return 0;
}