#include <iostream>
#include <vector>
using namespace std;

int Fibonacci(int n) {
  vector<int> saved(n+1, -1);
  if (n <= 2)
    return 1;
  if (saved[n] == -1) {
    saved[n] = Fibonacci(n-1) + Fibonacci(n-2);
  }
  return saved[n];
}


int main()
{
  int n;
  cin >> n;
  cout << Fibonacci(n) << endl;

  return 0;
}