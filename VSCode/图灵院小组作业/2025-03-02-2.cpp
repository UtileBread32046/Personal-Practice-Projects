#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

struct participants {
  int k;
  int s;
};

bool compare(participants &a, participants &b) {
  return a.s > b.s || (a.s == b.s && a.k < b.k);
}

int main()
{
  int n, m;
  cin >> n >> m;
  participants p[n];
  for (auto &x: p) {
    cin >> x.k >> x.s;
  }
  sort(p, p+n, compare);

  int people = floor(m*1.5);
  int score = p[people-1].s;
  cout << score << " ";
  int sum = 0;
  for (auto &x: p) {
    if (x.s >= score)
      sum++;
  }
  cout << sum << endl;
  for (auto &x: p) 
    if (x.s >= score)
      cout << x.k << " " << x.s << endl;


  return 0;
}