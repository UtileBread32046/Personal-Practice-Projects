#include <iostream>
#include <string>
using namespace std;

int main()
{
  string str;
  cin >> str;
  for (int i = 0; i < str.length(); i++) {
    if (isupper(str[i])) {
      str[i] = (str[i]+5-'A') % 26 + 'A';
    }
    else if (islower(str[i])) {
      str[i] = (str[i]+5-'a') % 26 + 'a';
    }
    else if (isdigit(str[i])) {
      str[i] = (str[i]+5-'0') % 10 + '0';
    }
  }
  cout << str << endl;

  return 0;
}