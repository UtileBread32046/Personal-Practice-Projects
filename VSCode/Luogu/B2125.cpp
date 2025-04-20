#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Student {
  int score;
  string name;
};

bool compare(const Student& a, const Student& b) {
  return a.score > b.score;
}

int main()
{
  int n;
  cin >> n;
  Student stu[n];
  for (auto &x: stu)
    cin >> x.score >> x.name;

  sort(stu, stu+n, compare);
  cout << stu[0].name << endl;  

  return 0;
}