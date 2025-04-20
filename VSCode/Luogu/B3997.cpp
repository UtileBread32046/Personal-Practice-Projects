#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  // 法一
  // string str;
  // cin >> str;
  // int len = str.length();
  // int i = 1;
  // int count = 0;

  // while (len > i) {
  //   string temp;
  //   temp.insert(temp.begin(), str.begin(), str.begin()+i);
  //   str.erase(0, i);
  //   int len_temp = temp.length();
  //   bool ok = true;
  //   for (int a = 0, b = len_temp-1; a < b; a++, b--) {
  //     if (temp[a] != temp[b]) {
  //       ok = false;
  //       break;
  //     }
  //   }
  //   if (ok)
  //     count++;
  //   i++;
  //   len = str.length();
  // }
  // bool ok = true;
  // for (int a = 0, b = len-1; a < b; a++, b--) {
  //   if (str[a] != str[b]) {
  //     ok = false;
  //     break;
  //   }
  // }
  // if (ok)
  //   count++;
  // cout << count;

  // 法二
  string str;
  cin >> str;
  int index = 0, length = 1, count = 0;
  while (index < str.length()) {
    string subStr = str.substr(index, length);
    index += length;
    length++;
    string revStr = subStr;
    reverse(revStr.begin(), revStr.end());
    count += (revStr == subStr);
  }
  cout << count;

  return 0;
}