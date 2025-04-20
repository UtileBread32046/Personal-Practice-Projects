#include <iostream>
#include <format>
using namespace std;

int main()
{
  double d = 0.0;
  cin >> d;
  cout << format("{:.12f}", d) << endl;

  return 0;
}