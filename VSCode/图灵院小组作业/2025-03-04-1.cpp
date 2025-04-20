#include <iostream>
using namespace std;

int main()
{
  int arr[5][5];
  for (auto &x: arr) {
    for (auto &y: x)
      cin >> y;
  }

  bool isFound = false;
  for (int i = 0; i < 5 && isFound == false; i++) {
    int index = -1;
    for (int j = 0; j < 5; j++) {
      if (arr[i][index] < arr[i][j] || index == -1) {
        index = j;
      }
    }
    int index_2 = -1;
    for (int k = 0; k < 5; k++) {
      if (arr[index_2][index] > arr[k][index] || index_2 == -1) {
        index_2 = k;
      }
    }
    if (i == index_2) {
      isFound = true;
      cout << i+1 << " " << index+1 << " " << arr[index_2][index] << endl;
      return 0;
    }
  }
  cout << "not found" << endl;

  return 0;
}