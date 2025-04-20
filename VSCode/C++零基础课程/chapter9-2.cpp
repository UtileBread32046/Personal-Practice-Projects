#include <iostream>
#include <string>
#include <math.h>
using namespace std;

// 访问控制的能力: 封装性
// 定义高精度大数类
struct BigInt0 {
 private: // 进行访问控制(外部不可访问), 使后续定义的内容变为私有的, 使得外部无法访问成员变量, 从而有效保护作为一个整体的数据被外部错误地修改
  int* digits = nullptr; // 定义一个int指针, 每个元素都代表数字的一位, 从低位到高位排列, 可以使用指针来动态申请(也可以使用vector)
 public: // 进行访问控制(外部可以访问)
  int size = 0; // 长度标识size来确定动态申请数组的长度
 protected: // (代表子类可访问)
  int sign = 0; // 让数组中的数字都是正数, 额外使用一个变量来代替符号(1代表正, -1代表负)
// friend xxx; // 访问控制的一种: 友元
};


// 类的定义
/* 类与结构体的区别
1. 关键字不同: struct, class
2. 默认的访问控制不同: struct默认为public, class默认是private(所以class不需要加private, 成员变量在外部就已经无法访问; 而class中加上public就等同于struct)
*/
// 如果数据只是简单地聚合, 可以随意让外部访问 → 使用struct
// 如果用于表示行为和状态的复杂对象, 不能随意让外部访问 → 使用class
// 类的访问控制的能力(封装性)是类的重要特性之一, 使得类可以表现得像一个实实在在的物体, 所以通过类定义的变量也称之为: 对象
class BigInt { // 默认情况下class下的变量因为封装而无法进行初始化
  int* digits = nullptr;
  int size = 0;
  int sign = 0;
 public: // 需要对外暴露相应的函数来进行初始化, 用于初始化的函数称为构造函数(此函数应和类名相同)
  // 构造函数
  BigInt(const string &str, int _sign) { // str前加上引用&避免性能开销; 同时加上const关键字, 就可以接受字符串字面量和临时计算结果作为参数
    sign = _sign;
    size = str.size();
    digits = new int[size]; // 申请对应大小的内存赋值给digits
    // 然后将string中的每一位赋值给digits的每一位(此处省略)
  }
  /* 简写: 在{}和()之间增加冒号:, 然后跟上成员变量的初始化(这样书写时即使参数名和成员变量名相同也可以正常解析)
  BigInt2(const string &str, int sign): sign(sign), size(str.size()) {
    digits = new int[size];
    // 后续代码省略
  } */
  BigInt(const BigInt &x) { // 重载默认构造函数
    sign = x.sign;
    size = x.size;
    digits = new int[size];
    memcpy(digits, x.digits, 4*size); // 将目标的digits复制一份到新对象
  }

  // 一个类可以有多个构造函数
  BigInt(long long x) {}
  BigInt() {}


  // 析构函数
  // 定义方式为波浪线~ + 类名, 不能跟参数, 并且只可定义一个
  // 调用时机是对象被销毁时, 不管是栈中的对象被自动销毁还是new出来的对象被手动delete, 都会自动调用析构函数
  ~BigInt() {
    if (digits == nullptr) return; // 检查是否为空指针, 如果是非空才进行delete
    delete[] digits;
    digits = nullptr; // 结束后应将其重置为nullptr, 避免成为野指针
  }


  // 成员函数
  // 只有定义在public下的函数才可以被外部调用, private下的函数只可在成员函数内调用
  // 在成员函数内, 可以直接访问任意相同类型对象的成员变量, 访问自身可以直接使用, 访问其他对象可以使用点.来访问对应的成员
  BigInt add(const BigInt &x) {
    BigInt ret; // 内部定义一个新对象
    int maxLen = max(size, x.size);
    ret.digits = new int[maxLen+1];
    // 此处省略累加代码
    return ret; // 将对象自身和参数的值累加到新对象上, 并返回新对象
  }

  void self_add(const BigInt &x) { // 不需要返回值(结果已经累加到自身)
    // 此处省略自增代码
  }

  BigInt& self_add2(BigInt* self, const BigInt &x) { // 对于没有返回值的成员函数, 可以将自身返回, 从而实现链式调用
    // 此处省略自增代码
    return *self; // 利用递归思想, 将自身作为参数进行传递, 然后返回self的解引用
  }

  BigInt& self_add3(const BigInt &x) { // C++中默认传递了自身指针, 此处不需要显式地声明和传递(BigInt* self)
    // 此处省略自增代码
    return *this;
  }


  // 运算符重载(操作符重载)
  // 运算符重载可以将函数名改成对应的运算符(需要operator关键字)
  BigInt operator + (const BigInt &x) {}
  BigInt& operator += (const BigInt &x) {}

  BigInt& output() {}

}; // 不要忘记分号;!!!


int main()
{
  BigInt a("123"s, 1); // 有了构造函数, 在定义对象时就可以跟上括号来进行初始化
  BigInt* ptr = new BigInt("345"s, -1); // 还可以使用new来新建对象, 括号内跟上的就是构造函数
  BigInt b = 1000; // 在只有一个参数的情况下, 可以直接使用等号=来进行初始化(不是赋值, 而是语法糖)
  BigInt c = {"789", 1}; // C++14后允许使用花括号{}包裹多个参数的语法来使用等号=进行初始化
  BigInt d; // 如果希望可以正常定义未初始化的对象, 就需要写一个无参数的构造函数, 或者设置其他构造函数的参数默认值(两种方法只可取其一, 否则会产生冲突)
  BigInt e(a); // class提供的默认构造函数: 使用另一个同类型的值来进行初始化

  string x, y;
  cin >> x >> y;
  BigInt X = x, Y = y;
  BigInt Z = X.add(Y); // C++中增加了返回值优化, 避免了临时对象的创建和销毁, 即此处的Z不存在空间上的复制
  X.self_add(Y); // 可以直接累加到调用的对象上, 这样不需要申请额外的空间就可以完成加法
  X.self_add2(&X, Y).self_add2(&X, Y); // 在调用时将自身的地址作为参数进行传递, 函数返回自身后可以实现链式调用
  X.self_add3(Y).self_add3(Y); // 当使用默认指针(this)时, 不需要在链式调用时传递额外地址参数
  BigInt Z2 = X + Y; // 代表使用符号后的操作数作为参数调用运算符重载函数
  Z2.output();



  return 0;
}