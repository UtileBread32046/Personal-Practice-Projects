#include <iostream>
#include <vector>
using namespace std;

long long power(int x, int n = 2) // 自定义函数中的参数为形式参数(parameter, 简称形参); 形参可以添加默认值(在形参后直接给参数赋值); 在存在多个参数的情况下, 不能前面的参数有默认值而后面的参数没有(因为传递参数的时候时按顺序一一对应的)
{
  if (x == 1)
    return 1; // 直接返回结果; return的作用除了返回结果外还会直接结束函数, 后续代码都不会执行; 使用自定义函数中的return可方便跳出多层循环嵌套
  long long res = 1;
  while (n--)
    res *= x;
  
  return res;
}

double power(double x, int n = 2) // 函数重载: 同名但参数类型和个数不同的函数会被视为不同的函数; 在实际调用时会根据参数信息智能推断该调用哪个函数
{
  double res = 1;
  while (n--)
    res *= x;

  return res;
}

void printHello(int n) // void类型返回值: 无返回值, 代表空, 不需要return
{
  if (n == 0)
    return; // 想要提前结束可使用不跟返回值的return
  for (int i = 0; i < n; i++)
    cout << "Hello!!!" << endl;
}

void swap(int &x, int &y) // 定义交换两个参数数值的函数(需加上取地址符&以更改实参的数值)
{
  int temp = x;
  x = y;
  y = temp;
}

// vector和sring类型的形参如果不使用&则会新建一个数据, 性能低效, 所以尽可能使用&
void forwardVector(vector <int> &vec);
void forwardString(string &str);

// 数组也存在隐式转化: 由数组转化成为指针, 意味着在自定义函数中无法再使用sizeof()得到数组长度*元素类型的长度, 得到的是指针的大小, 范围循环也无法再使用(因为指针并不具备数组的特性)
void forward1(int arr[])
{
  cout << typeid(arr).name() << endl; // typeid(): 输出参数类型
}
void forward2(auto &arr); // 在C++20中可通过auto &的方式将数组传递给函数; 使用auto定义函数的参数较为危险(调用时不易知道需要传入什么值, 所以不建议使用)
void forward3(int (&arr)[3]); // 使用此种写法代替上面的auto(需要指定数组的长度)
template <size_t N> // 也可使用C++中的模板来自定义数组的长度
void forward4(int (&arr)[N]);

int main(int argc, char** argv) // argument+count=argc: 实参个数; argument+vector=argv(一说指value): 实参向量 
{
  cout << power(2, 3) << endl; // 调用时的函数为实际参数(argument, 简称实参); 当实参传递的类型不同时, 会直接进行隐式转换(前提是可以进行隐式转换的类型)((e.g.)power(2.1,3.1)为double→int)
  cout << power(2) << endl; // 当形参中包含默认值时, 可自动将其补充到未输入的参数(若正常输入则以输入结果为准);
  cout << power(2.1, 3.1) << endl;
  int arr[] = {1, 2, 3};
  cout << typeid(arr).name() << endl; // typeid(): 输出参数类型
  forward1(arr);
}