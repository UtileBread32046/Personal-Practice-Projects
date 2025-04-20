#include <iostream>
#include <string>
using namespace std;

struct Student {
  string num;
  string name;
  int s1;
  int s2;
  int s3;
};

int main()
{
  int n;
  cin >> n;
  Student stu[n];
  for (auto &x: stu) {
    cin >> x.num >> x.name >> x.s1 >> x.s2 >> x.s3;
    cout << x.num << ',' << x.name << ',' << x.s1 << ',' << x.s2 << ',' << x.s3 << endl;
  }
  

  return 0;
}