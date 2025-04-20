#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
  int Array1[10];
  int a = 0;
  cout << "请输入为数组2设置的元素个数: ";
  cin >> a;

  // 在正常使用C++标准时不可用变量来规定数组长度, 但如果使用GCC编译器则会添加使用变量的情况, 不会报错
  int Array2[a] = {};


  // 不可通过cin/cout来输入/出数组元素, 当使用cout直接输出数组时会返回数组的十六进制地址
  cout << "数组1所在地址为: " << Array1 << endl;


  // 需通过循环依次进行数组元素的输入
  // 必须注意数组从0开始计数, 如果需要使用循环当前执行次数进行输出应设置初始值为0, 否则会超出数组长度而报错
  cout << "请为数组1输入10个元素: ";
  for (int i = 0; i < 10; i++)
    cin >> Array1[i];
  cout << "数组1中的元素分别为: " << endl;
  for (int i = 0; i < 10; i++)
    cout << Array1[i] << " ";
  cout << endl;


  // C++11中添加"范围循环"语法, 可以更为方便地遍历数组
  // 使用auto可以简化书写流程, 使范围循环保持一致
  cout << "再次打印数组1中元素: " << endl;
  for (auto x: Array1) // 此处相当于将Array1[i]依次赋值给变量x
    cout << x << " ";
  cout << endl;
  cout << "请为数组2输入" << a << "个元素: ";
  for (auto &y: Array2) // 通过改变变量的方式更改数组元素时需将变量名前面加上取地址符&
    cin >> y;
  cout << "数组2中的元素分别为: " << endl;
  for (auto y: Array2)
    cout << y << " ";
  cout << endl;


  // 数组的统一赋值初始化方法
  // 使用<algorithm>头文件中的fill函数
  int Array3[10];
  fill(Array3, Array3+5, 1); // fill(起点, 终点, 赋值)
  // 使用<string.h>头文件中的memset函数; memory+set=memset: 内存存储
  // 注意: 在使用memset函数时赋值必须是0或-1(不是1), 否则会出现乱码
  memset(Array3+5, 0, 5*sizeof(int)); // memset(起点, 赋值, 内存长度)
  cout << "数组3中的元素分别为: " << endl;
  for (int x: Array3)
   cout << x << " ";
  cout << endl;


  // 多维数组
  int grid[4][5] =  // grid:格子
  {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9},
    {10, 11, 12},
    {13, 14},
  };
  cout << "二维数组4中的元素分别为: " << endl;
  for (auto x: grid)
    cout << x << " ";
  cout << endl;
  memset(grid, 0, sizeof(grid)); // 通过以数组的长度赋值来进行整个数组的初始化
  cout << "再次打印二维数组4中的元素: " << endl;
  for (auto &x: grid)
    cout << x << " ";
  cout << endl;
  
  return 0;
}