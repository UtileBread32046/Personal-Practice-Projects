#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Survivor {
  string name;
  int proficiency;
};

struct Hunter {
  string name;
  int proficiency;
};

bool compare(const Survivor& a, const Survivor& b) {
  return a.proficiency > b.proficiency;
}

bool compare(const Hunter& a, const Hunter& b) {
  return a.proficiency > b.proficiency;
}

int main()
{
  int n, m;
  cin >> n >> m;
  Survivor sur[n];
  Hunter hun[m];
  int sum_s = 0;
  int sum_h = 0;
  for (int i = 0; i < n+m; i++) {
    string name;
    cin >> name;
    char c;
    cin >> c;
    if (c == 'S') {
      sur[sum_s].name = name;
      cin >> sur[sum_s].proficiency;
      sum_s++;
    }
    else {
      hun[sum_h].name = name;
      cin >> hun[sum_h].proficiency;
      sum_h++;
    }
  }

  sort(sur, sur+n, compare);
  sort(hun, hun+m, compare);
  cout << hun[5].name << endl;
  for (int i = 2; i < 2+4; i++) {
    cout << sur[i].name << endl;
  }

  return 0;
}