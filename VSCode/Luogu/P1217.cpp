#include <iostream>
#include <math.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
  int a, b = 0;
  int i, j = 0;
  int sum = 0;
  vector <int> p;
  vector <int> q;
  vector <int> ok;
  cin >> a >> b;
  // 寻找质数
  for (i = a; i <= b; i++) {
    for (j = 2; j <= sqrt(i); j++) {
      if (i % j == 0)
        break;
      }
    if (j > sqrt(i)) {
      sum++;
      p.push_back(i);
    }
  }
  for (auto &x: p) {
    reverse(x, x+strlen(x));
  }

  // for (int x = 0; x < (int)p.size(); x++) {
  //   int num = p[x];
  //   int original = num;
  //   int reverse = 0;
  //   int num_2 = num;
  //   int num_3 = num;
  //   while (num > 0) {
  //     reverse = reverse*10 + num%10;
  //     num /= 10;
  //   }
  //   if (reverse == original)
  //     ok.push_back(p[x]);
  // }

  // for (int x = a; x <= b; x++) {
  //   int num = x;
  //   int original = num;
  //   int reverse = 0;
  //   int num_2 = num;
  //   int num_3 = num;
  //   while (num > 0) {
  //     reverse = reverse*10 + num%10;
  //     num /= 10;
  //   }
  //   if (reverse == original)
  //     p.push_back(x);
  // }
  // for (i = 0; i < (int)p.size(); i++) {
  //   for (j = 2; j <= sqrt(p[i]); j++) {
  //     if (p[i] % j == 0) {
  //       p.erase(p.begin()+i);
  //       continue;
  //     }
  //     }
  //   if (j > sqrt(p[i])) {
  //     sum++;
  //     ok.push_back(p[i]);
  //   }
  //   else
  //     p.erase(p.begin()+i);
  // }
  for (auto &x: ok)
    cout << x << endl;

  return 0;
}