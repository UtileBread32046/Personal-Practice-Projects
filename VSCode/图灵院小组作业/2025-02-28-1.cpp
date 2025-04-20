#include <iostream>
#include <string>
using namespace std;

int judge(string a, string b) {
  if (a == b) return 0;
  else if (a == "Rock" && b == "Scissors") return 1;
  else if (a == "Scissors" && b == "Paper") return 1;
  else if (a == "Paper" && b == "Rock") return 1;
  else return -1;
}

int main()
{
  int n;
  cin >> n;
  while (n--) {
    string a, b;
    cin >> a >> b;
    switch (judge(a, b)) {
      case 0:
        cout << "Tie" << endl;
        break;
      case 1:
        cout << "Player1" << endl;
        break;
      case -1:
        cout << "Player2" << endl;
    }
  }

  return 0;
}