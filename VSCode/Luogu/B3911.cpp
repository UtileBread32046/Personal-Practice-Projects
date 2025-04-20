#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
  //法一, 但是不知道凭什么过不去
  int n, k = 0;
  cin >> n >> k;
  vector <string> variates;
  vector <int> values;

  while (n--) {
    string variate;
    cin >> variate;
    variates.push_back(variate);
    int value = 0;
    cin >> value;
    values.push_back(value);
  }

  while (getchar() != '\n'); // 当下面使用getline(cin, )时会先读取回车字符, 为防止输入数据丢失此处需提前将回车字符读取

  while (k--) {
    string sentence;
    getline(cin, sentence);
    int position_left = sentence.find("{");
    while (sentence.find("{") != string::npos) {
      int position_right = sentence.find("}");
      string get_variate = sentence.substr(position_left+1, position_right-position_left-1);
      int i = 0;
      for (; i < (int)sizeof(variates); i++) {
        if (variates[i] == get_variate)
          break;
      }
      int length = position_right-position_left+1;
      sentence.replace(position_left, length, to_string(values[i]));
      position_left = sentence.find("{", position_left+1);
    }
    cout << sentence << endl;
  }


  // 法二
  // int n, k;
  // cin >> n >> k;
  // string names[n];
  // int values[n];
  // for (int i = 0; i < n; i++)
  //   cin >> names[i] >> values[i];

  // while (getchar() != '\n');

  // while (k--) {
  //   string str;
  //   getline(cin, str);
  //   int left = str.find("{");
  //   while (left != string::npos) {
  //     int right = str.find("}");
  //     string name = str.substr(left+1, right-left-1);
  //     int value;
  //     for (int i = 0; i < n; i++) {
  //       if (name == names[i]) {
  //         value = values[i];
  //         break;
  //       }
  //     }
  //     str.replace(left, right-left+1, to_string(value));
  //     left = str.find("{", left+1);
  //   }
  //   cout << str << endl;
  // }

  return 0;
}