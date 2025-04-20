#include <iostream>
#include <string>
#include <math.h>
using namespace std;

struct student
{
  string name;
  int Chinese;
  int math;
  int English;
  int total;
};
int main()
{
  int n;
  cin >> n;
  struct student students[n];
  for (int i = 0; i < n; i++) {
    cin >> students[i].name >> students[i].Chinese >> students[i].math >> students[i].English;
    students[i].total = students[i].Chinese + students[i].math + students[i].English;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (abs(students[i].Chinese-students[j].Chinese) <= 5 && abs(students[i].math-students[j].math) <= 5 && abs(students[i].English-students[j].English) <= 5 && abs(students[i].total-students[j].total) <= 10) {
        cout << students[i].name << " " << students[j].name << endl;
      }
    }
  }

  return 0;
}