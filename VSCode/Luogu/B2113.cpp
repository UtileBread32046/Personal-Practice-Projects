#include <iostream>
#include <string.h>
using namespace std;

int main()
{
  char str[100];
  cin >> str;
  int len = (int)strlen(str);
  int init = str[0];
  // 应当特别注意字符串的实际长度需+1, 末尾存在终止字符\0, 不可直接加到其他字符上
  for (int i = 0; i < len-1; i++) {
    str[i] += str[i+1];
  }
  str[len-1] += init;
  cout << str;

  return 0;
}