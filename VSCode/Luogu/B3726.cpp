#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
  int n, q = 0;
  cin >> n >> q;
  vector <string> strs(n);
  for (auto &str: strs)
    cin >> str;
  
  while (q--) {
    int a = 0;
    scanf("%d", &a);
    if (a == 1) {
      int x, y, i = 0;
      scanf("%d %d %d", &x, &y, &i);
      // auto &sx = strs[x-1];
      // auto &sy = strs[y-1];
      // sy.insert(sy.begin()+i, sx.begin(), sx.end());
      strs[y-1].insert(i, strs[x-1]);
    }
    if (a == 2) {
      int y = 0;
      scanf("%d", &y);
      auto &sy = strs[y-1];
      cout << sy << endl;
    }
  }

  return 0;
}