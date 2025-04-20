#include <iostream>
#include <format>
using namespace std;

int main()
{
  int a, b, c = 0;
  cin >> a >> b >> c;
  cout << format("{:>8} {:>8} {:>8}", a, b, c) << endl;
}