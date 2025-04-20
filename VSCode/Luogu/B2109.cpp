#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;

int main()
{
  int sum = 0;
  char str[256]; // 字符串最后包含终止符\0, 所以总长度需+1
  cin.getline(str, 256); // 输入内容中包含空格, 需使用.getline()
  for (unsigned long i = 0; i < strlen(str); i++) {
    if (isdigit(str[i]))
      sum++;
  }
  cout << sum;

  return 0;
}