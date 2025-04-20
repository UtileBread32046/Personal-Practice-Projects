#include <iostream>
#include <string>
using namespace std;

int main()
{
  string str;
  cin >> str;
  int len = str.length();
  // int temp = str[0]-48;
  char c = str[0];
  int count = 1;
  
  for (int i = 1; i <= len; i++) { // 此处需越界否则无法完成最后一串数字的计数
    // if (temp == str[i]-48) {
    if (c == str[i]) {
      count++;
    }
    else {
      // cout << count << temp;
      cout << count << c;
      count = 1;
    }
    // temp = str[i]-48;
    c = str[i];
  }

  
  return 0;
}