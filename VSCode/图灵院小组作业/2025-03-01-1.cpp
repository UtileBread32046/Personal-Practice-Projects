#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  double sum = 0;
  while (n--) {
    int a;
    cin >> a;
    while (a > 0) {
      sum += 0.1;
      a -= 70;
    }
  }
  cout << sum << endl;

  return 0;
}