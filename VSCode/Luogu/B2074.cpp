#include <iostream>
using namespace std;

int main()
{
  int a, b = 0;
  int result = 1;
  cin >> a >> b;
  for (int i = 1; i <= b; i++)
  {
    result *= a;
    result %= 7;
  }
  switch (result)
  {
    case 1:
      cout << "Monday";
      break;
    case 2:
      cout << "Tuesday";
      break;
    case 3:
      cout << "Wednesday";
      break;
    case 4:
      cout << "Thursday";
      break;
    case 5:
      cout << "Friday";
      break;
    case 6:
      cout << "Saturday";
      break;
    case 0:
      cout << "Sunday";
      break;
  }

  return 0;
}