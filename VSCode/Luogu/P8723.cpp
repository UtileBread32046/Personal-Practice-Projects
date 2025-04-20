#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string base(int P)
{
  // char c[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  // char choose[P];
  string s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string choose(s.begin(), s.begin()+P);
  return choose;
}

void print(int P)
{
  string choose = base(P);
  // cout << choose << endl;
  for (int i = 1; i < P; i++) {
    for (int j = 1; j <= i; j++) {
      int result = i*j;
      string answer;
      while (result > 0) {
        answer += choose[result % P];
        result /= P;
      }
      reverse(answer.begin(), answer.end());
      printf("%c*%c=%s ", choose[i], choose[j], answer.c_str());
    }
    cout << endl; 
  }
  return;
}

int main()
{
  int P = 0;
  cin >> P;
  base(P);
  print(P);

  return 0;
}