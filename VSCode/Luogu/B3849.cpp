#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
  int N, R;
  int r = 0;
  cin >> N >> R;
  vector <char> result;
  vector <char> letter{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' , 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

  while (N>0) {
      r = N % R;
      N /= R;
      result.insert(result.begin(), *(letter.begin()+r));
  }

  for (auto &x: result)
    cout << x;

  return 0;
}