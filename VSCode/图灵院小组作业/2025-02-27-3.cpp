#include <iostream>
#include <string>
using namespace std;

int main()
{
  double judge;
  cin >> judge;
  string str1, str2;
  cin >> str1 >> str2;
  int len = str1.length();
  int sum = 0;
  for (int i = 0; i < len; i++) {
    if (str1[i] == str2[i])
      sum++;
  }
  double result = sum*1.0/len;
  cout << (result >= judge ? "yes" : "no") << endl;


  return 0;
}