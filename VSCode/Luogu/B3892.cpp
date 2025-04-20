#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

int main()
{
  int n, q = 0;
  cin >> n >> q;
  char delimiter[] = "x+=";
  vector <int> num;
  vector <int> result;

  while (n--) {
    char formula[1000];
    cin >> formula;
    auto token = strtok(formula, delimiter);
    int x = 0;
    while (token) {
      num.push_back(atoi(token));
      token = strtok(NULL, delimiter);
    }
    x = (num[2]-num[1])/num[0];
    result.push_back(x);
    num.clear();
  }

  while (q--) {
    int l, r = 0;
    cin >> l >> r;
    int sum = 0;
    for (int k = l; k <= r; k++) {
      for (auto &i: result) {
        if (k == i) {
          sum++;
          break;
        }
      }
    }
    cout << sum << endl;
  }

  return 0;
}