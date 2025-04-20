#include <iostream>
#include <string>
using namespace std;

int main()
{
  int n;
  char a;
  string str;
  int sum = 0;
  cin >> n >> a;

  for (int k = 1; k <= n; k++ ) {
    for (int i = 1; i <= k; i++)
      str += a;
    sum += stoi(str);
    str.clear();
  }
  cout << sum << endl;


  return 0;
}