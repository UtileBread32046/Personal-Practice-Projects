#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int arr[n][n];
  for (auto &x: arr) {
    for (auto &y: x)
      cin >> y;
  }

  int saved_line = -1, saved_column = -1;
  // 判断行
  for (int i = 0; i < n; i++) {
    int line = 0;
    for (int j = 0; j < n; j++) {
      line += arr[i][j];
    }
    if (line % 2 != 0) {
      if (saved_line == -1)
        saved_line = i+1;
      else {
        cout << "Corrupt" << endl;
        return 0;
      }
    }
  }
  // 判断列
  for (int j = 0; j < n; j++) {
    int column = 0;
    for (int i = 0; i < n; i++) {
      column += arr[i][j];
    }
    if (column % 2 != 0) {
      if (saved_column == -1)
        saved_column = j+1;
      else {
        cout << "Corrupt" << endl;
        return 0;
      }
    }
  }
  
  if (saved_line == -1 && saved_column == -1)
    cout << "OK" << endl;
  else {
    cout << saved_line << " " << saved_column << endl;
  }

  return 0;
}