#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n, t = 0;
  cin >> n >> t;
  vector <int> stu_num(n);
  for (auto &x: stu_num)
    cin >> x;
  vector <int> new_num;
  while (t--) {
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
      for (int j = i; j < n; j += k) {
        new_num.push_back(stu_num[j]);
      }
    }
    stu_num = new_num;
    new_num.clear();
  }
    for (auto &x: stu_num)
      cout << x << " ";
    cout << endl;

  return 0;
}