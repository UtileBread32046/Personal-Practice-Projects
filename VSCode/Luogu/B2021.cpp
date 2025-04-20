#include <iostream>
#include <format>
using namespace std;

int main()
{
  float f = 0.0;
  cin >> f;
  cout << format("{:.3f}", f) << endl;

  return 0;
}