#include <iostream>
using namespace std;

int main()
{
  int n, m = 0;
  cin >> n >> m;
  int A[n][m];
  int T[m][n];

  for (auto &x: A) {
    for (auto &y: x) {
      cin >> y;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      T[j][i] = A[i][j];
    }
  }

  for (auto &x: T) {
    for (auto &y: x) {
      cout << y << " ";
    }
    cout << endl;
  }

  return 0;
}