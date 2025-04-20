#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n = 0;
  cin >> n;
  vector <int> p(n);
  for (auto &x: p) {
    cin >> x;
  }

  do {
    p.insert(p.begin(), p.back());
    p.erase(p.end());
    for (auto &x: p) {
      cout << x << " ";
    }
    cout << endl;
  }
  while (p.back() != n);

  return 0;
}