#include <iostream>
#include <vector>
using namespace std;

double f(double x, int n) {
  vector<double> saved(2*n, -1);
  if (n == 1) return x*1.0/(1+x);
  if (saved[n] == -1) {
    saved[n] = x*1.0/(n+f(x, n-1)); // 本质上是求相邻两项的递推公式
  }
  return saved[n];
}

int main()
{
  double x;
  int n;
  cin >> x >> n;
  cout.precision(2);
  cout << fixed;
  cout << f(x, n);

  return 0;
}