#include <iostream>
#include <format>
using namespace std;

int main()
{
  long long N = 0;
  cin >> N;
  while(N>1)
  {
    if (N%2 == 1)
    {
      cout << format("{}*3+1={}", N, N*3 + 1) << endl;
      N = N*3 + 1;
    }
    else
    {
      cout << format("{}/2={}", N, N / 2) << endl;
      N = N / 2;
    }
  }
  if (N == 1)
    cout << "End";

  return 0;
}