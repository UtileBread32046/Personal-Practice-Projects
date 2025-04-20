#include <iostream>
using namespace std;

int main()
{
  int n, m, k;
  cin >> n >> m >> k;
  int A[n][m];
  int B[m][k];
  for (auto &x: A) {
    for (auto &y: x)
      cin >> y;
  }
  for (auto &x: B) {
    for (auto &y: x)
      cin >> y;
  }
  int C[n][k] = {};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      for (int l = 0; l < m; l++) {
        C[i][j] += A[i][l] * B[l][j];
      }
    }
  }

  for (auto &x: C) {
    for (auto &y: x)
      cout << y << " ";
    cout << endl;
  }

  return 0;
}