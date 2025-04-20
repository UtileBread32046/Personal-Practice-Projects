#include <iostream>
using namespace std;

int main()
{
  /* 逻辑运算 */
  // 比较运算
  int a = 1;
  int b = 2;
  cout << boolalpha;
  // cout是一个特殊的操作符, 当后面内容进行逻辑判断时需加上括号, 否则因操作之间的计算顺序而导致错误
  cout << (a == b) << endl; 
  cout << (a != b) << endl;
  cout << (a < b) << endl;
  cout << (a > b) << endl;
  cout << (a <= b) << endl;
  cout << (a >= b) << endl;
  // C++20中新增三路比较运算符(宇宙飞船运算符): <=>, 可返回两个数的顺序关系(可表示小于等于大于三种结果)
  auto order = a <=> b; // 通过auto承载三路比较运算符的比较结果
  cout << (order < 0) << endl;
  cout << (order == 0) << endl;
  cout << (order > 0) << endl;

  // 逻辑运算
  // &&:与; ||:或; !:非

  // 条件运算(三目运算)
  int x = 1;
  cout << (x%2 ? "odd" : "even") << endl; // ?前判断为true时执行左式, 判断为false时执行右式; 也需要在输出时为整体加上括号
  

  /* 条件控制*/
  if (true) 
  {
    // {}内为作用域, 可重新初始化同名变量, 此处初始化与赋值的作用不同, 不会改变{}外同名变量的值
    int a = 10;
    cout << a << endl;
  }
  cout << a << endl; // if作用域内初始化的同名变量对外界无影响
  
  // C++17中新增if的初始化, 可在if后的()内初始化变量, 该变量仅在该if逻辑判断内有意义(包括if分支, else分支), 结束后自动销毁
  if (int power = x*x; power < 100)
    cout << power << endl;
  else
    cout << power - 1;

  // puts函数: 输出确定的一段字符串, 且可以自动换行
  puts("positive");
  puts("negative");

  return 0;
}