#include <iostream>
#include <vector>
using namespace std;

int Sum(auto& mines, int x, int y, int n, int m) {
  int sum = 0;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0) continue;
      if (0 <= x+i && x+i < n && 0 <= y+j && y+j < m && mines[x+i][y+j] == '*')
          sum++;
    }
  }

  return sum;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<char> > mines(n, vector<char>(m, '?'));
  for (auto &x: mines) {
    for (auto &y: x)
      cin >> y;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mines[i][j] == '?')
        mines[i][j] = '0' + Sum(mines, i, j, n, m);
    }
  }

  for (auto &x: mines) {
    for (auto &y: x)
      cout << y;
    cout << endl;
  }

  return 0;
}