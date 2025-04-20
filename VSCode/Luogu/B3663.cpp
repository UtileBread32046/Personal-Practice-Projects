#include <iostream>
#include <string>
using namespace std;

int main()
{
  string str;
  cin >> str;
  int position = 0;
  int count = 0;
  
  // 法一: 耗时长
  // while (position != string::npos) {
  //   position = str.find("luogu", position);
  //   if (position != string::npos) {
  //     count++;
  //     str.erase(position, 5);
  //   }
  // }

  // 法二: 耗时短
  position = str.find("luogu");
  while (position != string::npos) {
    count++;
    position = str.find("luogu", position+1);
  }

  cout << count;

  return 0;
}