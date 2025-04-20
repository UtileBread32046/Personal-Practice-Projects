#include <iostream>
using namespace std;

int main()
{
  int m, n, sx, sy;
  cin >> m >> n >> sx >> sy;
  cout << sx << " " << sy << endl;
  while (n--) {
    for (int i = 1; i <= 2*m; i++) {
      int a, b;
      cin >> a >> b;
      if (a == 0 && b == 0) {
        return 0;
      }
      else {
        cout << a << " " << b << endl;
      }
    }
  }

  return 0;
}