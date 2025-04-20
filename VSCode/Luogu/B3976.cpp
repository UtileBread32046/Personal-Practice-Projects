#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int main()
{
  string str;
  cin >> str;
  bool ok = false;
  int i = 0;

  // 超时算法
  // while (!ok) {
  //   ok = true;
  //   int len = str.length();
  //   for (i; i < len; i++) {
  //     if (!(isalpha(str[i]))) {
  //       ok = false;
  //       str.erase(i, 1);
  //       break;
  //     }
  //   }
  // }
  // cout << str;

  string result;
  for (auto &c: str) {
    if (isalpha(c))
      result += c;
  }
  cout << result;

  return 0;
}