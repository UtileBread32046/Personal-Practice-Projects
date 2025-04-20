#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
  char str[100];
  cin >> str;

  // 法一: 颠倒法
  // char initial[100];
  // strcpy(initial, str);
  // reverse(str, str+strlen(str));

  // cout << (strcmp(str, initial) == 0 ? "yes" : "no");

  // 法二: 前后对比法
  bool diff = false;
  for (int i = 0, j = (int)strlen(str)-1; i < j; i++, j--) {
    if (str[i] != str[j]) {
      diff = true;
      break;
    }
  }

  cout << (diff == false ? "yes" : "no");

  return 0;
}