#include <iostream>
using namespace std;

int main()
{
  int n = 0;
  cin >> n;
  int Array[n];
  for (auto &i: Array)
    cin >> i;
  while (n--)
    cout << Array[n] << " ";

  return 0;
}