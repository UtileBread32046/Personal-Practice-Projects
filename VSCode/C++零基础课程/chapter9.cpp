#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// 类的前身: 结构体
// 结构体作用: 将多个类型聚合为一个整体成为一个新类型
// 将结构体定义在全局, 这样在任何函数内都可以访问
struct Student {
  int score; // {}中的变量称为成员变量, 是结构体的成员
  string name;
} stu1, stus1[100]; // 变量和花括号后都需要加分号; ; 特殊的定义方式: 直接在结构体后面跟上变量名

struct { // 可以不写类型名 → 匿名结构体(但是无法正常定义其他变量)
  int score;
  string name;
} stu2;


int main()
{
  Student stu, stus[100]; // 像普通类型一样声明定义变量或数组
  Student* pstu = new Student; // 定义在全局区, 栈区, 堆区
  decltype(stu2) stus2[100]; // 通过C++11中新增的decltype关键字获取到匿名的类型; declared+type=decltype, 可以推导某个表达式的声明类型
  stu.score; // 通过结构体变量加点号.就可以访问内部的成员变量

  int n = 8;
  Student* stus3 = new Student[8];
  for (int i = 0; i < 8; i++) {
    cin >> stus[i].score >> stus[i].name;
  }
  sort(stus3, stus3+n, [](Student &a, Student &b) { // 结构体默认不支持大小比较. 所以我们需要写一个自定义比较函数; 参数是两个Student, 注意需要使用引用&, 避免结构体传参时发生拷贝引起的性能问题
    return a.score < b.score; // 在比较函数内写下比较方法
  });

  struct B {}; // 定义在函数(某个作用域)内
  if (true) {
    struct C {};
  }
  struct D {
    struct E {}; // 也包括结构体内部的花括号(结构体嵌套定义)
  };

  // 结构体的初始化
  Student a = {99, "小明"}; // 使用花括号(要和结构体内成员函数的定义顺序对应)
  Student b = {99}; // 只初始化部分成员变量
  Student c{99}; // 直接在变量后加上花括号进行初始化 (最常见)
  auto d = Student{99}; // 使用auto进行定义
  Student e{.name="小明"}; // 在C++20中增加了指定成员进行初始化的方法
  Student b2 = b; // 结构体的变量也可以直接进行赋值, 直接将目标数据拷贝一份到新变量
  Student c2;
  c2 = c;


  // 结构体大小
  // 结构体的大小并非所有成员变量的大小之和, 而是会进行内存对齐
  /* 结构体内存对齐规则:
  * 1. 以最大的类型作为宽度构建一个矩阵; 复合数据结构以内部成员变量的最大宽度作为宽度; 数组也并不是以整体作为宽度, 而是以元素的类型作为宽度
  * 2. 按照定义顺序依次摆放
  * 3. 每个数据只能摆放在其大小的倍数的位置; char可以摆放在任意位置, int是4字节, 只能摆放在0或4的位置
  * 4. 当一行摆不下时, 就新起一行, 不能插入之前的空位
  * 5. 最终行*列就是这个结构体的实际大小
  */
  // 根据内存对齐规则会有极大的空间浪费, 但这可以加速计算机对数据的访问
  // 如果希望内存利用率更高, 可以按从大到小的方式定义成员变量
  struct S {
    char c;
    int i;
    short s;
    double d;
    char c2;
  };


  // 结构化绑定(C++17新增)
  auto [score, name] = stu; // 可以将结构体内的成员变量绑定到新的变量上(但必须绑定所有的成员变量, 不允许只绑定部分)
  auto& [score1, name1] = stu; // 也可以使用引用&, 避免产生数据拷贝
  auto& [s2, n2] = stu; // 新的变量名和成员变量不需要同名, 只需要顺序对应上即可
  for (auto &[score3, name3] : stus1) { // 结合范围循环, 就可以很方便地遍历结构体数组
    cin >> score3 >> name3;
  }
  for (auto &[score4, _] : stus1) {} // 如果只想使用部分变量, 可以在结构化绑定时将不需要的变量命名为下划线_ (既不破坏结构化绑定的语法, 又可以表示这个变量后续不会被使用)(不是语法而是一种清晰化的命名规范)


  // C++中两种更为简便的方式定义纯数据结构体
  pair<int, string> a1; // <>内部填上两个类型并用逗号分隔
  a1.first; // 有两个成员变量(但未进行命名), 可以使用.first和.second来进行访问
  a1.second;
  pair<int, string> a2{99, "小明"}; // 支持花括号{}初始化
  auto &[f, s] = a2; // 支持结构化绑定
  auto a3 = make_pair(80, "小赵"); // 当使用auto进行定义时需要使用make_pair函数来设置初始值
  a2 <=> a3; // 如果两个类型均支持大小比较, 则pair也支持大小比较

  vector < pair<int, string> > stus3(n);
  for (auto& [s, f] : stus3) { // 结构化绑定再读入数据
    cin >> s >> f;
  }
  sort(stus3.begin(), stus3.end()); // 可以直接调用sort函数, 不需要写自定义比较函数

  tuple<int, int, string> a4{99, 7, "小明"}; // 当需要填入超过两个元素时, 可使用C++11中新增的tuple
  auto &[score, id, name] = a4;
  auto a5 = make_tuple(80, 8, "小赵");
  a4 <=> a5;
  // tuple无法使用pair中.first和.second的方式来访问成员变量, 需使用get
  get<0>(a4);
  get<1>(a4);
  get<2>(a4);


  // 除结构化绑定外, pair和tuple还可以使用tie函数绑定成员变量到已定义的变量上
  tie(score, name) = pis;
  tie(score, id, name) = tiis;

  vector <pair<int, string> > vec;
  vec.push_back(make_pair(99, "小明")); // C++11之前需使用make_pair将数据组装成pair再push_back进vector
  vec.push_back({95, "小郭"}); // C++11中加入列表初始化, 可以直接用花括号{}代替make_pair
  vec.emplace_back(80, "小赵"); // 使用emplace_back可以直接将数据作为参数传入; 同时也会提升性能(直接构造对象而无需进行复制), 所以对于复合类型, 尽可能使用emplace_back代替push_back


  return 0; 
}