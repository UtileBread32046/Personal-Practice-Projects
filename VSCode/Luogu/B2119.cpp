#include <iostream>
#include <string.h>
using namespace std;

int main()
{
  char str[33];
  cin >> str;
  int len = (int)strlen(str);
  
  // 法一: 逐一判断法
  // if (strcmp(str+len-2, "er") == 0) {
  //   str[len-2] = 0;
  // }
  // else if (strcmp(str+len-2, "ly") == 0)
  //   str[len-2] = 0;
  // else if (strcmp(str+len-3, "ing") == 0)
  //   str[len-3] = 0;

  // 法二: 循环判断法
  char patterns[][4] = {"er", "ly", "ing"}; // 将字符串保存在二维数组中方便存取
  for (auto &p: patterns) {
    int l = strlen(p);
    if (strcmp(str+len-l, p) == 0)
      str[len-l] = 0;
  }

  cout << str;

  return 0;
}