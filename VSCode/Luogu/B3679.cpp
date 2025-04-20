#include <iostream>
using namespace std;

struct mmj {
  int x;
  int y;
};

struct qsz {
  int x;
  int y;
};

struct jgz {
  int x;
  int y;
};

int main()
{
  int n, k, t;
  cin >> n >> k >> t;
  mmj mmj[n];
  qsz qsz[k];
  jgz jgz[t];
  for (auto &i: mmj) cin >> i.x >> i.y;
  for (auto &i: qsz) cin >> i.x >> i.y;
  for (auto &i: jgz) cin >> i.x >> i.y;

  return 0;
}