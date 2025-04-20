#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Kitty(auto &result, string str) {
  if (str.find('1') == string::npos) {
    result.push_back('A');
    return;
  }
  if (str.find('0') == string::npos) {
    result.push_back('B');
    return;
  }
  int len = str.length();
  len /= 2;
  result.push_back('C');
  Kitty(result, str.substr(0, len));
  Kitty(result, str.substr(len, len));
}

int main()
{
  string str;
  cin >> str;
  vector<char> result;
  Kitty(result, str);
  for (auto &x: result)
    cout << x;
  cout << endl;

  return 0;
}