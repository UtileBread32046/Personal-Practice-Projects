#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s, t;
  cin >> s >> t;
  int q = 0;
  cin >> q;

  while (q--) {
    int l1, r1, l2, r2 = 0;
    cin >> l1 >> r1 >> l2 >> r2;
    string temp_s = s.substr(l1-1, r1-l1+1); // 长度不是r1-l1而应该是r1-l1+1!!!(下标1~2是2个不是1个)
    string temp_t = t.substr(l2-1, r2-l2+1);
    
    auto order = temp_s <=> temp_t; // 使用三路比较运算符<=>只需比较一次字符串, 速度更快
    if (order == 0)
      cout << "ovo";
    else if (order > 0)
      cout << "erfusuer";
    else
      cout << "yifusuyi";

    cout << endl;
    }

  return 0;
}