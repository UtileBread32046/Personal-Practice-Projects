#include <iostream>
using namespace std;

double judge(int arr[], int i, int j, int n) {
  int sum = 0;
  for (int k = 0; k < n; k++) {
    if (i <= arr[k] && arr[k] <= j)
      sum++;
  }
  return sum*1.0/n*100;
}

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (auto &x: arr)
    cin >> x;

  cout.precision(2);
  cout << fixed;
  cout << judge(arr, 0, 18, n) << "%" << endl;
  cout << judge(arr, 19, 35, n) << "%" << endl;
  cout << judge(arr, 36, 60, n) << "%" << endl;
  cout << judge(arr, 61, 1000, n) << "%" << endl;


  return 0;
}