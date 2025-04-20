#include <iostream>
#include <format>
using namespace std;

int main()
{
  char c = 'a';
  int a = 0;
  float f = 0.0;
  double d = 0.0;
  cin >> c >> a >> f >> d;
  cout << c << " " << a << " " << format("{:.6f}", f) << " " << format("{:.6f}", d) << endl;

  return 0;
}