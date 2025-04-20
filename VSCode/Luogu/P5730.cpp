#include <iostream>
#include <string>
using namespace std;

void one(int number)
{
  switch (number) {
    case 1:
      cout << "..X";
      break;
    case 0:
    case 2:
    case 3:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
      cout << "XXX";
      break;
    case 4:
      cout << "X.X";
      break;
  }
}
void two(int number) {
  switch (number) {
    case 1:
    case 2:
    case 3:
    case 7:
      cout << "..X";
      break;
    case 0:
    case 4:
    case 8:
    case 9:
      cout << "X.X";
      break;
    case 5:
    case 6:
      cout << "X..";
      break;
  }
}
void three(int number) {
  switch (number) {
    case 0:
      cout << "X.X";
      break;
    case 1:
    case 7:
      cout << "..X";
      break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 8:
    case 9:
      cout << "XXX";
      break;
  }
}
void four(int number) {
  switch (number) {
    case 0:
    case 6:
    case 8:
      cout << "X.X";
      break;
    case 2:
      cout << "X..";
      break;
    case 1:
    case 3:
    case 4:
    case 5:
    case 7:
    case 9:
      cout << "..X";
      break;
  }
}
void five(int number) {
  switch (number) {
    case 0:
    case 2:
    case 3:
    case 5:
    case 6:
    case 8:
    case 9:
      cout << "XXX";
      break;
    case 1:
    case 4:
    case 7:
      cout << "..X";
      break;
  }
}
int main()
{
  int n;
  cin >> n;
  string str;
  cin >> str;
  for (int i = 0; i < n; i++) {
    one(str[i] - '0');
    if (i != n - 1)
      cout << ".";
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    two(str[i] - '0');
    if (i != n - 1)
      cout << ".";
  }
  cout << endl;
    for (int i = 0; i < n; i++) {
    three(str[i] - '0');
    if (i != n - 1)
      cout << ".";
  }
  cout << endl;
    for (int i = 0; i < n; i++) {
    four(str[i] - '0');
    if (i != n - 1)
      cout << ".";
  }
  cout << endl;
    for (int i = 0; i < n; i++) {
    five(str[i] - '0');
    if (i != n - 1)
      cout << ".";
  }
  cout << endl;

  return 0;
}