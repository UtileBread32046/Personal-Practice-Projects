#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int logo(string str) {
  int result = 0;
  // FD → D; BK → K; REPEAT → T
  if (str.find('D') == string::npos && str.find('K') == string::npos && str.find('T') == string::npos)
    return result;
  int FD = str.find('D');
  if (FD != -1) {

  }
}

int main()
{
  string str;
  getline(cin, str);
  logo(str); 

  return 0;
}