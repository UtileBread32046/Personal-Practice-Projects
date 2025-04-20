#include <iostream>
#include <string>
using namespace std;

bool mix_safe_1(string str) {
  int len = str.length();
  for (int i = 1; i < len; i++) {
    if (islower(str[i])) return true;
  }
  return false;
}

bool mix_safe_2(string str) {
  int len = str.length();
  for (int i = 1; i < len; i++) {
    if (isdigit(str[i])) return true;
  }
  return false;
}

bool mix_safe_3(string str) {
  int len = str.length();
  for (int i = 1; i < len; i++) {
    if (str[i] == '~' || str[i] == '!' || str[i] == '@' || str[i] == '#' || str[i] == '$' || str[i] == '%' || str[i] == '*') return true;
  }
  return false;
}

int main()
{
  string str;
  cin >> str;
  int len = str.length();
  bool safe = true;

  if (!(8 <= len && len <= 16)) safe = false;
  if (!isupper(str[0])) safe = false;
  if (!(mix_safe_1(str) && mix_safe_2(str) && mix_safe_3(str))) safe = false;

  cout << (safe ? "true" : "false") << endl;

  return 0;
}