#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 法一
bool isInteger(string str) {
  for (int i = 0; i < str.length(); i++) {
    if (!isdigit(str[i])) {
      return false;
    }
  }
  return true;
}

void rev(string str) {
  string temp_1, temp_2;
  if (isInteger(str)) {
    reverse(str.begin(), str.end());
    while (str.front() == '0' && str.length() > 1) str.erase(0, 1);
    cout << str;
  }
  else {
    int index = 0;
    for (index; index < str.length(); index++) {
      if (!isdigit(str[index])) break;
    }
    char c = str[index];
    
    // reverse在<algorithm>头文件中属于void类型函数, 无法返回任何值, 所以不能直接令temp_1 = reverse(...)
    // 此处需先使用.substr()将原字符串复制到temp_1中再进行反转
    temp_1 = str.substr(0, index);
    temp_2 = str.substr(index+1);
    reverse(temp_1.begin(), temp_1.end());
    reverse(temp_2.begin(), temp_2.end());
    while (temp_1.front() == '0' && temp_1.length() > 1) temp_1.erase(0, 1);

    switch (c) {
      case '.':
        while (temp_2.back() == '0' && temp_2.length() > 1) temp_2.pop_back();
        break;
      case '/':
        while (temp_2.front() == '0' && temp_2.length() > 1) temp_2.erase(0, 1);
        break;
      case '%':
        temp_2.clear();
        break;
    }
    cout << temp_1 << c << temp_2 << endl;
  }
}

// 法二
void reverse(string str) { // 函数重载(参数不一样)
  int l = 0, r = str.length() - 1; // 取起始和末尾索引
  while (l <= r && str[l] == '0') l++; // 抹除前置0
  while (l <= r && str[r] == '0') r--; // 抹除后置0
  if (l > r) { // 判断是否剩余字符
    cout << '0';
    return;
  }
  for (int i = r; i >= l; i--)
    cout << str[i]; // 倒序输出
}

int main()
{
  string str;
  cin >> str;
  
  // 法一
  // rev(str);

  // 法二
  string delimiters = "./"; // 设置分隔符
  for (char &delimiter: delimiters) {
    if (size_t pos = str.find(delimiter); pos != string::npos) { // 在if()内部初始化变量pos, 起到限制作用域的效果
      reverse(str.substr(0, pos));
      cout << delimiter;
      reverse(str.substr(pos+1));
      cout << endl;
      return 0; // 后续代码无需继续运行, 可提前结束
    }
  }
  if (str.back() == '%') {
    str.pop_back(); // 只保留'%'前面数字
    reverse(str);
    cout << '%' << endl;
    return 0;
  }
  reverse(str);
  cout << endl;

  return 0; // main()函数中也可以不在末尾加上return 0;
}