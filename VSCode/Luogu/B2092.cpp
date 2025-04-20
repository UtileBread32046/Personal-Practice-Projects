#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int N = 0;
  cin >> N;
  int light[N] = {0};
  fill(light, light+N, 1);
  for (int i = 0; i < N; i++)
  {
    for (int r = 1; r<=N; r++)
    {
      if (r % (i+1) == 0)
        light[r-1]++;
    }
  }
  for (int j = 0; j < N; j++)
  {
    if (light[j] % 2 == 0)
      cout << j+1 << " ";
  }


  return 0;
}