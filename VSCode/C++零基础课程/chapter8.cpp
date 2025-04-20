#include <iostream>
#include <vector>
using namespace std;

int add(int a, int b)
{
  return a + b;
}
int main()
{
  // 类型转换:
  // 通过取地址符将一个变量的地址强制转换为另一种类型的指针, 从而实现不同类型之间的转换
  long long ll = 353;
  cout << "long long: " << ll << endl;
  cout << "bool: " << *(bool *)&ll << endl;
  cout << "char: " << *(char *)&ll << endl;
  cout << "int: " << *(int *)&ll << endl;
  cout << "double: " << *(double *)&ll << endl; // 将原本long long类型的值用double重新解释;
  // 该方法和直接将long long转成double不同, 并不是对值进行转换, 而是将内存当中的数据用double来解释
  /*
  *  1.&ll:用过取地址获取到变量的地址;
  *  2.(double*): 将这个地址转为double类型指针;
  *  3.*: 通过指针的解引用, 将该内存地址往后的8个字节的内存以double来解释
  */

  // 指针类型转换:
  void* ptr = (void *)0x123456789; // 将0x123456789转换为void*类型的指针
  int i = 1;
  int* ptr2 = &i; // 将i的地址转换为void*类型的指针
  double d = 1.0;
  int* ptr3 = (int*)&d; // 将d的地址强制转换为int*类型的指针
  void* ptr4 = &i; // void*类型的指针可以指向任何类型的变量(只是地址, 没有指定类型信息, 因此可以存储任意类型数据的地址)
  // 使用void*类型的指针获取值时只需再转成对应的类型即可, 因此void*也被成为万能指针

  // 指针的取值(指针解引用): 根据指针将值取出来的操作:
  int var = 1;
  int* ptr5 = &var;
  cout << *ptr5 << endl; // 在指针变量前加上星号*可以自动获取指针指向的变量的值(解引用), 即根据指针的类型来解释地址对应的内存数据
  *ptr5 = 2;
  cout << var << endl;
  var = 3;
  cout << *ptr5 << endl;
  // 上述代码均是对同一块内存数据的操作
  // void指针无法进行解引用(因为没有定义类型)

  // 多级指针:
  i = 1;
  int* p = &i; // 定义一个指向整型变量的指针 p，并将变量 i 的地址赋值给它
  int** pp = &p; // 定义一个指向整型指针的指针 pp，并将指针 p 的地址赋值给它
  int*** ppp = &pp; // 定义一个指向整型指针的指针的指针 ppp，并将指针 pp 的地址赋值给它
  cout << *p << " "; // 输出指针 p 指向的值，即变量 i 的值
  cout << *pp << " "; // 输出指针 pp 指向的地址，即指针 p 的地址
  cout << **pp << " "; // 输出指针 pp 指向的指针（即 p）指向的值，即变量 i 的值
  cout << *ppp << " "; // 输出指针 ppp 指向的地址，即指针 pp 的地址
  cout << **ppp << " ";  // 输出指针 ppp 指向的指针（即 pp）指向的指针（即 p）指向的值，即变量 i 的值
  cout << ***ppp << endl;  // 输出指针 ppp 指向的指针（即 pp）指向的指针（即 p）指向的值，即变量 i 的值

  // 不可进行解引用的指针(会造成程序崩溃)
  // 野指针: 未进行初始化的指针, 瞎指
  int *p1;
  *p1;
  // 空指针: 将指针初始化为空
  int *p2 = NULL; // 将指针初始化为空指针
  *p2;
  int *p3 = nullptr; // 为防止NULL与0混淆, C++11引入了nullptr, 表示空指针
  *p3;

  // 指针与数组
  int arr[5] = {1, 2, 3, 4, 5};
  int* ptr_arr = &(arr[0]); // 与int* ptr_arr = arr;的效果相同; 当将数组赋值给指针时发生了隐式转换(int*)(即第一个元素的首地址)
  for (int i = 0; i < 5; i++)
    cout << ptr_arr[i] << ' '; // ptr[i]: 偏移指针(语法糖), 将算数运算和解引用合二为一; 偏移指针不可在偏移结果不明确的情况下使用
  cout << endl;
  // 数组 != 指针
  int (*ptr_arr2)[5] = &arr; // 数组arr的实际类型是int[5], 如果想令指针指向整个数组, 需要在ptr后也加上[5], 且需要用括号()将星号*和变量名括起来以区分指针数组和指向数组的指针
  cout << sizeof(arr) << " ";
  cout << sizeof(ptr_arr) << " ";
  cout << sizeof(ptr_arr2) << " ";
  cout << sizeof(*ptr_arr2) << " " << endl;
  cout << typeid(arr).name() << " ";
  cout << typeid(ptr_arr).name() << " ";
  cout << typeid(ptr_arr2).name() << " ";
  cout << typeid(*ptr_arr2).name() << " " << endl;
  using Array5 = int[5]; // 使用using将数据类型重新取名以避免混淆
  Array5 arr2 = {1, 2, 3, 4, 5};
  Array5* ptr_arr3 = &arr2; // 即可像普通变量一样定义数组和指向数组的指针

  // 指针与字符串
  char *ps;
  cout << (void*)ps << endl; // 获取char类型指针的地址时需使用(void*)进行类型转换
  char str[] = "hello";
  char *pstr = str; // 将带有终止符的字符数组首元素地址赋值给字符指针可以将指针直接当字符串使用, 但如果仅将单个字符的地址赋值给字符指针, 依然会当成字符串处理, 将会输出乱码
  cout << pstr << endl;
  char* str2 = "123"; // 特殊的字符指针: 直接初始化为双引号所包含的字符串字面量; 该指针无法像字符数组一样修改值

  // 指针与对象
  vector<int> vec;
  vector<int> *pvec = &vec;
  (*pvec).push_back(1); // 指针解引用后可以使用对象的成员函数
  ptr->push_back(2); // 通过箭头->直接进行对象内的函数调用(语法糖)

  // 指针与函数
  int (*pfun)(int, int) = add; // 将函数的地址保存到指针变量中, 需使用括号()将星号*和变量名括起来
  cout << pfun(1, 2) << endl; // 可以像普通函数一样使用函数指针

  return 0;
}