#include <iostream>
using namespace std;

int main()
{
  int N = 0;
  cin >> N;
  // if (N > 0)
  //   cout << "positive";
  // else if (N < 0)
  //   cout << "negative";
  // else
  //   cout << "zero";

  if (N != 0)
    cout << ((N>0) ? "positive" : "negative");
  else
    cout << "zero";
  
  return 0;
}