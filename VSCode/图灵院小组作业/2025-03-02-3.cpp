#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Students {
  string name;
  int score;
};

bool compare(Students &a, Students &b) {
  return a.score > b.score || (a.score == b.score && a.name < b.name);
}

int main()
{
  int n;
  cin >> n;
  Students stu[n];
  for (auto &x: stu)
    cin >> x.name >> x.score;
  sort(stu, stu+n, compare);
  for (auto &x: stu)
    cout << x.name << " " << x.score << endl;

  return 0;
}