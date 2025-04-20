#include <iostream>
using namespace std;

class Obj {
  double x, y, w, h;
  int life, attack;
 public:
  bool test(Obj* other);
};

// 继承
// 继承另一个类(父类)的成员变量和函数
// 父类/基类: 被继承的类; 子类/派生类: 继承的类
// 子类可以访问父类的public和protected成员, 但不可访问private成员
// protected专为继承而设计, 在子类中可以像public一样访问, 但在外部会像private一样无法被访问
// 构造函数和析构函数无法被继承, 除非显式地调用父类的构造函数
class Plant : Obj { // 在类的声明中加上冒号:和另一个类被继承的类
  int coolDown;
};
class one : public Plant {}; // 可在冒号:和父类之间加上权限修饰词(不写默认为private)可决定父类的成员在子类中以什么权限存在(不影响子类对父类的访问)
class A final {}; // 如果一个类被final修饰, 则该类无法被继承


// 多态
// 静态多态: 在编译器中确定需要调用哪个同名函数; 动态多态: 在程序运行期确定调用哪个函数
class Base {
  int *ptr = nullptr;
 public:
  Base() { ptr = new int[10]; }
  virtual ~Base() { delete[] ptr; } // 虚函数: 在父类中使用virtual关键字来进行修饰的函数, 从而实现多态; 为了防止内存泄漏, 在有多态的场景下, 基类的析构函数建议都写成虚函数
  virtual void clicked() = 0; // 纯虚函数: 在父类中没有实现, 在函数末尾写上=0来表示, 强制子类必须重写该函数的虚函数; 如果一个类有纯虚函数, 那么就不能直接创建该类的对象, 而只能创建子类的对象
};
class Drived: public Base {
  int *ptr2 = nullptr;
 public:
  Drived() { ptr2 = new int[10]; }
  ~Drived() override { delete[] ptr2; } // 在子类中重新虚函数时, 建议加上override关键字, 代表这个函数是对虚函数的重写, 这样在编译时就可以检查是否正确重写了父类的虚函数, 避免函数名拼错/参数类型不对等情况出现
};


int main()
{
  return 0;
}