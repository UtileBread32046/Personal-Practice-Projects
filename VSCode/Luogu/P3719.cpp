#include <iostream>
#include <string>
using namespace std;

void regex(string str) {
  string result;
  if (str.find('(') == string::npos && str.find('|') == string::npos) {
    result += str;
    return;
  }
  
}

int main()
{
  string str;
  cin >> str;


  return 0;
}