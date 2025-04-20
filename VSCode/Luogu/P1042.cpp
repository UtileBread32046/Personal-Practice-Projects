#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool over(int a, int b, int num) {
  if (a>=num && a-b>=2 || b>=num && b-a>=2)
    return true;
  return false;
}

void judge(char c, vector<int> &score, int num) {
  if (c == 'W') {
    score[0]++;
  }
  else if (c == 'L') {
    score[1]++;
  }
  if (over(score[0], score[1], num)) {
    cout << score[0] << ':' << score[1] << endl;
    score[0] = 0, score[1] = 0;
  }
}

int main()
{
  char c;
  c = getchar();
  vector<int> score(2);
  string str;

  while (c != 'E') {
    str += c;
    judge(c, score, 11);
    c = getchar();
  }
  cout << score[0] << ':' << score[1] << endl;
  score[0] = 0, score[1] = 0; // 不要忘记此处需要重置分数以判断新的分制下结果!!!
  cout << endl;
  for (int i = 0; i < str.length(); i++) {
    judge(str[i], score, 21);
  }
  cout << score[0] << ':' << score[1] << endl;
  
  return 0;
}