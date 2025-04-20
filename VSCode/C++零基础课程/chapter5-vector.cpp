#include <iostream>
#include <vector>
using namespace std;
/* Standard+Template+Library=STL: 标准模板库; C++标准库中的一部分, 可帮助处理常见的数据结构和算法
 * 容器: STL的重要组成部分, 用于存储和组织数据的对象
 * vector: 动态数组容器
 * vector无需在声明时确定大小, 可以做到动态调整容量
 * vector <类型> 变量名; 创建二维数组时使用vector<vector <类型>> 变量名
 * vector在取值/索引时既可以使用下标[], 也可以使用.at(); 使用.at()时如果越界则会报错 */

int main()
{
  int n = 10;
  // 初始化
  vector <int> vi;
  vector <int> v1(5); // 规定vector数组的长度, 并默认填入0
  vector <int> v2(5, 1); // 规定vector数组的长度, 并填入()中,后的数值
  vector <int> v3{1, 2, 3, 4, 5}; // 仿照数组定义初始值
  vector <int> v4(v1); // 通过另一个vector进行初始化
  vector <vector<int> > v5(2, vector<int>(8, 3)); // 二维vector的初始化, 由于元素是vector<int>, 初始化参数也应改为vector<int>的初始值
  auto v6 = vector(2, vector(8, 3)); // 利用auto自动类型推导, 可以更方便的进行多维vector的初始化

  // 输入
  // 当未初始化vector的大小时:
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    // 由于vector在声明时内部没有任何数据, 在输入时需要读取数据到某个变量, 然后push_back()将变量放入容器中
    vi.push_back(x);
  }
  // 当对vector的大小进行初始化时:
  for (auto &x: v1) {
    cin >> x;
  }

  // 输出
  // 在输出时可以通过.size()获取到容器的大小, 然后用常规for循环进行输出
  for (int i = 0; i < vi.size(); i++) {
    cout << vi[i] << endl;
  }
  // vector也支持范围循环来遍历整个容器内的元素
  for (auto &x: vi) {
    cout << x << endl;
  }

  // 赋值运算
  v1 = v2; // 将一个vector中的数值直接赋值给另一个vector
  // 比较运算
  v2 < v3; // 依次比较两个vector中元素的大小(类似于英文字典的排序方式)(字典序)
  
  // 常用成员函数
  cout << v1.front() << endl; // .front(): 获取vector的第一个元素
  cout << v1.back() << endl; // .back(): 获取vector的最后一个元素
  cout << v1.size() << endl; // .size(): 获取vector当前的元素个数
  cout << v1.empty() << endl; // .empty(): 判断vactor当前是否为空
  vi.clear(); // .clear(): 清空vector的数据
  vi.push_back(1); // .push_back(): 将()中的数据添加到vector的末尾
  vi.pop_back(); // .pop_back(): 将vector中最后一个数据移除
  vi.resize(5); // .resize(): 将()中的数值重新定义为vector的大小; 如果比原先小, 则会删除末尾的元素; 如果比原先大, 则会用0来填充新增的元素
  vi.resize(10, 1); // 使用()中第二个数值(即,后的数值)来填充新增的元素

  // 迭代器: 分别指向容器的始末, 通过迭代器可以访问容器中的元素, 也可以用来定位位置从而增添/删除元素
  vi.begin(); // 返回vector起始迭代器
  vi.end(); // 返回vector末尾迭代器
  // vector <int>::iterator: 迭代器的类型, 可直接用auto代替
  // for (vector <int>::iterator iter = v.begin(); iter != v.end(); iter++) // 依次遍历vector的所有元素
  // 此处的循环和输出也可用范围循环for(auto &x:v1)来代替
  for (auto iter = v1.begin(); iter != v1.end(); iter++) { // 其中的iter++不是算数运算, 而是让迭代器指向下一个元素
    *iter; // 因为迭代器并非元素本身, 而是指向元素, 所以当想要获取迭代器所指向的元素的值时, 需要在迭代器之前加上星号*
  }
  v1.erase(v1.begin()); // .erase(): 删除元素; 如果()中只有一个参数, 则代表删除指定位置的元素
  v1.erase(v1.begin(), v1.begin()+3); // 如果()中有两个参数, 则代表删除某段连续的元素
  v1.insert(v1.begin(), 1); // .insert(): 插入元素; ()内第一个参数值作为插入位置, 后面的参数代表插入内容
  v1.insert(v1.begin(), {1, 2, 3}); // 插入元素也可以是一组花括号{}表示的数据
  v1.insert(v1.begin(), v2.begin(), v2.end()); // 插入元素还可以是另一个容器的范围, 此行代码可将一个容器放到另一个容器的尾部

  return 0;
}
