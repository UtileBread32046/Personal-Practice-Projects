#include <iostream>
using namespace std;

int main()
{
  int a, b = 0;
  // int calculator = 0;
  char c;
  cin >> a >> b >> c;
  // if (c == '+')
  //   calculator += 1;
  // if (c == '-')
  //   calculator += 2;
  // if (c == '*')
  //   calculator += 3;
  // if (c == '/')
  //   calculator += 4;
  // switch (calculator)
  switch (c)
  {
  default:
    cout << "Invalid operator!";
    break;
  case '+':
    cout << a + b;
    break;
  case '-':
    cout << a - b;
    break;
  case '*':
    cout << a * b;
    break;
  case '/':
    if (b == 0)
      cout << "Divided by zero!";
    else
      cout << a/b;
    break;
  }

  return 0;
}