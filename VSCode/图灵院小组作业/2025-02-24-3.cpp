#include <iostream>
using namespace std;

int main()
{
  double bike = 27+23;
  double walk = 0;
  int n = 0;
  cin >> n;
  bike += n / 3.0;
  walk += n / 1.2;

  auto judge = bike <=> walk;
  if (judge < 0)
    cout << "骑车" << endl;
  else if (judge > 0)
    cout << "走路" << endl;
  else
    cout << "一样快" << endl;


  return 0;
}