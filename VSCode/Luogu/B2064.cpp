#include <iostream>
using namespace std;

int main()
{
  int n = 0;
  int Array[30] = {1, 1};
  for (int i = 2; i < 30; i++)
    Array[i] = Array[i-1] + Array[i-2];
  cin >> n;
  int num[n] = {};
  for (auto &a: num)
    cin >> a;
  for (auto a: num)
    cout << Array[a-1] << endl;

  return 0;
}