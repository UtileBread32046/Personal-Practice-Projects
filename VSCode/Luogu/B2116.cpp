#include <iostream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;

int main()
{
  char str[50];
  cin >> str;
  int len = (int)strlen(str);
  for (int i = 0; i < len; i++) {
    if (isupper(str[i])) {
      str[i] = (str[i] - 'A' + 29) % 26 + 'A';
      str[i] = tolower(str[i]);
      continue;
    }
    if (islower(str[i])) {
      str[i] = (str[i] - 'a' + 29) % 26 + 'a';
      str[i] = toupper(str[i]);
      continue;
    }
  }
  reverse(str, str+len);
  cout << str;
  

  return 0;
}