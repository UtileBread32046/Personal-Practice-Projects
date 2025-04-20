#include <iostream>
using namespace std;

int main()
{
  int m;
  cin >> m;
  int arr[m];
  for (auto &x: arr)
    cin >> x;
  
  int min_index = 0;
  for (int i = 1; i < m; i++) {
    if (arr[min_index] > arr[i])
      min_index = i;
  }
  int max_index = 0;
  for (int i = 1; i < m; i++) {
    if (arr[max_index] < arr[i])
      max_index = i;
  }

  cout << arr[max_index] - arr[min_index] << endl;

  return 0;
}