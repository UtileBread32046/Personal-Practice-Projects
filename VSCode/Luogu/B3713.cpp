#include <iostream>
#include <string>
#include <format>
#include <vector>
using namespace std;

int main()
{
  int n, m = 0;
  cin >> n >> m;
  vector <string> questions(m);
  for (auto &question: questions)
    cin >> question;


  // 法一
  // vector <vector <string> > participants(n);

  // for (int i = 0; i < n; i++) {
  //   auto &participant = participants[i];
  //   for (int j = 0; j < m+1; j++) {
  //     string content;
  //     cin >> content;
  //     participant.push_back(content);
  //   }
  //   bool happy = false;
  //   for (int k = 0; k < m; k++) {
  //     string answer;
  //     string result = participant[k+1];
  //     answer += participant[0] + ".zip/" + participant[0] + '/' + questions[k] + '/' + questions[k] + ".cpp";
  //     if (answer == result)
  //       happy = true;
  //     else
  //       happy = false;
  //     cout << (happy ? "Fusu is happy!" : "Fusu is angry!") << endl;
  //   }
  // }


  // 法二
  while (n--) {
    string id;
    cin >> id;
    for (auto &question: questions) {
      string pattern;
      cin >> pattern;
      if (pattern == format("{0}.zip/{0}/{1}/{1}.cpp", id, question))
        cout << "Fusu is happy!" << endl;
      else
        cout << "Fusu is angry!" << endl;
    }
  }

  return 0;
}