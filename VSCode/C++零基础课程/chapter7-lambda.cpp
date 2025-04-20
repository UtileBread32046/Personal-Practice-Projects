#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comparer(int a, int b) // 正常定义函数
{
  if (a%2 != b%2) { // 判断a, b的奇偶性是否相同
    return a%2 == 1; // 判断a的奇偶性(奇数放在前面)
  }
  return a < b; // 如果奇偶性相同, 则按从小到大的顺序进行排序
}

int main()
{
  int n = 8;
  int arr1[n] = {5, 8, 4, 3, 2,  7, 1, 6};
  int arr2[n] = {5, 8, 4, 3, 2,  7, 1, 6};
  // sort() // <algorithm>头文件中的sort函数: 将一个范围的元素按从小到大的顺序进行重排列
  // void sort(Iterator first, Iterator last, Function comparer);
  // 采取左闭右开的区间[first, last); 当想以特定的方式进行排序时, 可引入一个函数作为第三个参数
  sort(arr1, arr1+n, comparer); // 对普通数组进行排序
  sort(arr2, arr2+n, [](int a, int b) -> bool { // 使用定义匿名函数的方法进行排序; -> 类型: 代表该匿名函数的返回值类型
    if (a%2 != b%2) {
      return a%2 == 1;
    }
    return a < b;
  }); // 注意此处的分号!!!

  vector<int> vec(n);
  sort(vec.begin(), vec.end()); // 对vector进行排序

  for (auto &x: arr1)
    cout << x << " ";
  cout << endl;
  for (auto &x: arr2)
    cout << x << " ";
  cout << endl;


  // find_if(Iterator first, Iterator last, Function matcher); // 第三个参数接受一个函数, 用于表示是否满足条件(返回值类型为bool, 参数为单个元素)
  // find_if的返回值是迭代器或地址, 所以需要在末尾减去起始迭代器或数组的起始地址才能得到下标
  vector<int> vec1 = {5, 8, 4, 3, 2, 100, 7, 1, 6};
  int target = 10;
  int index = find_if(vec1.begin(), vec1.end(), [target](int x) { // []: 捕获一些变量使得其可以在函数内正常访问
    return x > target;
  }) - vec1.begin(); // 减去起始迭代器以获得下标


  // []捕获capture:
  /* 值捕获: 
      [x]() { 可以在函数内访问x, 但无法修改
        x;
        x = 1;
      };
  *  引用捕获: 
      [&x]() { 在x前加上取地址符&, 此时可对x的值进行修改
        x = 1;
      };
  *  隐式捕获: 
      [=]() { 捕获所有的变量(值捕获)
        x, y, z;
      };
      [&]() { 捕获所有的变量(引用捕获)
        x = y = z = 1;
      };
      [x, &y]() {
        x; 值捕获x
        y = 1; 引用捕获y
      };
      [&, x]() { 值捕获x, 其余变量均为引用捕获  
        x;
        y = z = 1;
      };
      [=, &x]() { 引用捕获x, 其余变量均为值捕获
        x = 1;
        y, z;
      };
  * 初始化捕获(C++14新增):
      [x, init = x*x]() { // 可以在捕获区定义有初始值的新变量, 该变量只在匿名函数区域内生效
        x, init;
      };
  */
  

  // 使用mutable关键字对匿名函数内变量进行更改:
  // int x = 5;
  // [x, init = x*x]() mutable { // mutable: 可改变的; 在()和{}之间加上mutable可以修改x的值
  //   x = init = 0;
  //   x; // 0
  // };
  // x; // 5; 使用mutable修改和使用引用&修改不同, mutable仅修改匿名函数内部的数值而对外部无影响

  index = find_if(vec1.begin(), vec1.end(), [target, count = 0](int x) mutable {
    // if (x > target) {
    //   ++count;
    //   if (count == 5) 
    //     return true;
    // }
    // 等价于
    return x > target && count++ == 5;
  }) - vec1.begin();

  auto swap = [](int &a, int &b) { // 通过匿名函数定义变量swap(可传入两个参数); 
  // 该变量类型只可使用auto来进行推导, 使用"函数指针"/"多态函数包装器"来定义都会改变原本类型
    int temp = a;
    a = b;
    b = temp;
  }; // 不要忘记此处的分号!!!

  auto Fibenacci = [](auto &self, int x) { // 在使用匿名函数进行递归调用时需使用auto &参数名的方式传递给自身
    if (x <= 2)
      return 1;
    return self(self, x-1) + self(self, x-2); // 递归调用时使用参数名而非变量名
  }; // 注意此处的分号!!!
  cout << Fibenacci(Fibenacci, 10) << endl; // 第一个参数是自身, 赋值给&self

  return 0;
}