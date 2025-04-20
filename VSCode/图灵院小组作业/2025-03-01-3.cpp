#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  getline(cin, s);
  int len = s.length();
  string s1 = s;
  
  for (int i = 0; i < len; i++) {
    s1[i] += s[(i+1)%len];
  }
  cout << s1 << endl;

  return 0;
}