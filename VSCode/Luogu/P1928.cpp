#include <iostream>
#include <string>
using namespace std;

string decode(string str) {
  string result;
  if (str.find('[') == string::npos) {
    
    return result;
  }
  int start = str.find('[');
  int end = 0;
  int sum = 0; // 对左括号数量进行计数
  for (size_t i = 0; i < str.length()/2; i++) {
    if (str[i] == '[')
      sum++;
  }
  while (sum--) {
    end = str.find(']', end+1);
  }

  int times = str[start+1] - '0';
  int len = end - start;
  string temp = str.substr(start+2, len-2);
  string change;
  while (times--) {
    change += temp;
  }
  str.replace(start, len+1, change);
  cout << temp << " " << str << endl;
  decode(str);
}

int main()
{
  string str;
  cin >> str;


  return 0;
}