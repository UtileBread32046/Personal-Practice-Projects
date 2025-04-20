#include <iostream>
using namespace std;

int main()
{
  double books[] = {28.9, 32.7, 45.6, 78, 35, 86.2, 27.8, 43, 56, 65};
  int length = sizeof(books)/sizeof(double);

  double sum = 0;
  for (int i = 0; i < length; i++) {
    int x;
    cin >> x;
    sum += books[i]*1.0*x;
  }
  cout.precision(1);
  cout << fixed;
  cout << sum << endl;

  return 0;
}