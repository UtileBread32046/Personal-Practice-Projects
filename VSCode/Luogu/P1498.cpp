#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void totem(auto &arr, int x, int y, int size) {
  if (size == 4) {
    arr[x][y+1] = 1;
    arr[x][y+2] = 2;
    arr[x+1][y] = 1;
    arr[x+1][y+1] = 3;
    arr[x+1][y+2] = 3;
    arr[x+1][y+3] = 2;
    return;
  }
  int edge = size / 2;
  // 特别注意x是行, y是列, 别搞反了!!!
  totem(arr, x, y+edge/2, edge); // 顶角
  totem(arr, x+edge/2, y, edge); // 左下角
  totem(arr, x+edge/2, y+edge, edge); // 右下角
}

int main()
{
  int n;
  cin >> n;
  int size = pow(2, n+1);
  auto arr = vector(size/2, vector(size, 0));
  totem(arr, 0, 0, size);
  
  for (auto &x: arr) {
    for (auto &y: x) {
      if (y == 0) cout << " ";
      else if (y == 1) cout << "/";
      else if (y == 2) cout << "\\";
      else if (y == 3) cout << "_";
    }
    cout << endl;
  }

  return 0;
}