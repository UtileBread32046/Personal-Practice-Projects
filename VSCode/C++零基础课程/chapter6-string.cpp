#include <iostream>
#include <string> // C++中的<string>头文件≠C语言中的<string.h>
#include <format>
using namespace std;

int main()
{
  // 定义
  string str;

  
  // 初始化
  string str1 = "012345"; // 使用等于号进行初始化
  string str2 = str1; // 使用另一个字符串进行初始化
  string str3(6, '#'); // 通过长度+字符的形式进行初始化
  string str4(str1); // 也可用括号代替等于号(使用括号进行初始化的方式叫做构造函数)
  string str5("012345");
  string str6(str1, 2); // 使用括号可以比使用等号放入更多参数
  string str7(str1, 2, 2); // 当第一个参数为string类型时, 第二个参数代表从第几个字符开始, 第三个参数代表使用多少个字符来初始化
  string str8("012345", 2); // 当第一个参数为字符串类型时, 第二个参数代表使用多少个字符来初始化
  string str9({48, '1', '2'}); // 列表初始化
  string str10(str1.begin() + 1, str1.end() - 1); // 迭代器初始化


  // 输入&输出
  cin >> str; // 直接使用cin会根据空格分隔(及出现空格后停止对当前字符串的输入)
  getline(cin, str); // getline(cin, ): 输入整行
  for (char &c: str) {} // 使用范围循环遍历string每个字符进行输入
  cout << str;


  // 操作
  // string与vector类似但不属于容器(因为string的类型固定为char, 而容器的元素可以自由定义)
  str2 = str1; // 支持赋值运算
  str1 <=> str2; // 比较运算
  str1[0]; // 下标访问运算
  str3 = str1 + str2; // "加法"运算, 将两个字符串合并, 结果是一个新的字符串
  str1 += "abc"; // 直接将字符(串)加到末尾
  str1 += 'd';


  // 函数
  // 访问
  .at() // 带范围监测的下标访问
  .front() // 获取第一个字符
  .back() // 获取最后一个字符
  .c_str() // 返回C语言字符串; 当使用printf("%s")时无法直接输出string类型, 可借助.c_str()来获取字符串

  // 迭代器
  .begin() // 起始迭代器
  .end() // 末尾迭代器

  // 容量
  .empty() // 判断字符串是否为空
  size // 获取字符个数
  .length() // 获取字符个数

  // 修改
  .clear() // 清空字符串
  .resize() // 改变大小
  .push_back() // 将字符插入末尾
  .pop_back() // 移除末尾字符
  .insert() // 插入字符(串); 在string中既可使用迭代器表示位置, 也可直接使用下标
  .erase() // 删除子串; 同理第一个参数也可直接使用下标表示从哪个字符开始删除, 以及第二个参数表示删除多少个字符(如果不填第二个参数则默认将第一个参数代表的位置开始的后续字符全部删除); (e.g.)str.erase(1, 2);
  .append() // 将字符串插入末尾; (e.g.)str.append("abc");
  .replace() // 替换一段子串; 相当于erase和insert的结合, 将字符串中的一段区间(第二个参数为被替换的字符串长度)替换为目标字符串; (e.g.)str.replace(1, 2, "xyz");

  // 操作
  .find() // 寻找子串首次出现位置(查找字符串是否包含另一个字符串, 如果找到则返回int类型的下标, 否则返回unsigned long long类型最大值的string::npos(等价于有符号的-1))); (e.g.)str.find("is"); str.find("is", 3); // 第二个参数指定从哪个下标开始查找
  .substr() // 返回指定子串; 根据下标以及长度返回一个子串, 如果不填长度则放回从下标位置到结尾的子串; (e.g.)str.substr(2, 3);
  .starts_with() // 前缀判断; 返回bool类型的值; (e.g.)str.starts_with("hel");
  .ends_with() // 后缀判断; (e.g.)str.ends_with("llo");

  stoi() // 将string转成数值; (e.g.)int i = stoi(str);
  stoll() // long long
  stod() // double
  to_string() // 将数值转成string; (e.g.)int i = 123; string str = to_string(i);
  format() //的真正作用: 构造string
  // 使用format更加格式化地构造string: (e.g.)double d = 1e9; string str = format("d = {:.0f}", d);

  return 0;
}