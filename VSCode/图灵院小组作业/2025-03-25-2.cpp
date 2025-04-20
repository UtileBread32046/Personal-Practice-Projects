#include <iostream>
#include <string>
using namespace std;

int main()
{
  string str;
  getline(cin, str);

  int max_len = 0;
  int max_idx = 0;
  size_t index = 0;

  while (index < str.length()) {
    size_t pos = str.find(' ', index);
    if (pos == string::npos)
      pos = str.length() - 1;
    int len = pos - index;
    if (max_len < len && len > 0) {
      max_len = len;
      max_idx = index;
    }
    index = pos+1;
  }
  cout << max_idx << " " << max_len << endl;

  return 0;
}