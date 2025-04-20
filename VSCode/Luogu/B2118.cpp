#include <iostream>
#include <string.h>
#include <format>
using namespace std;

int main()
{
  // 傻逼出题数据范围写错了
  char s1[25], s2[25];
  cin >> s1 >> s2;
  if (strstr(s1, s2))
    cout << format("{} is substring of {}", s2, s1);
  else if (strstr(s2, s1))
    cout << format("{} is substring of {}", s1, s2);
  else
    cout << format("No substring");

  return 0;
}