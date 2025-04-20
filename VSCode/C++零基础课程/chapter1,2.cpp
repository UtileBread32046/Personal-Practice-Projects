#include <iostream> // 输入输出流:input+output+stream=iostream; 可以省略C语言中指定类型的繁琐步骤
#include <format> // C++20中新增的头文件, 其中的format函数可作为C语言中printf的上位替代
using namespace std; // namespace:命名空间; 也可使用std::来调用标准库中的函数

int main()
{
  /*
  * cin:标准输入流, 将终端中的字符输入给程序中的变量(根据需要将输入的字符转化成变量对应类型的数据); character+in=cin
  * cout:标准输出流, 将数据以字符的形式打印到终端; character+out=cout
  * endl:换行; end+line=endl(与\n类似, 但相对而言endl可以保证输出的内容立即显示)
  * 此处可理解为cout代表着终端, <<使右侧数据流向终端
  * 使用"<<"">>"等符号代替函数调用的做法称为操作符重载
  */
  int input = 0;
  int a = 1;
  int b = 2;
  cin >> input;
  cout << "Hello,World!" << endl;
  cout << input << endl;
  cout << format("{} + {} = {}", a, b, a+b) << endl;

  getchar(); // 等待字符输入, 使exe文件双击运行完后窗口不自行关闭
}
