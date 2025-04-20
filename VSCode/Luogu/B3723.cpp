#include <iostream>
#include <vector>
using namespace std;

// 法三
void getCoin(vector<long long> &coins, long long &sum) { // 使用引用从而直接修改值
  int index = -1;
  int mini = 0;
  for (int i = 0; i < coins.size(); i++) {
    if (coins[i] <= sum) { // 若存在小于手中硬币总数的面额
      if (index == -1 || coins[i] > coins[index]) { // 挑出剩余硬币中最大的一个
        index = i;
      }
    }
    if (coins[i] < coins[mini]) { // 挑出剩余硬币中最小的一个
      mini = i;
    }
  }
  if (index == -1) index = mini; // 如果桌面上剩余的所有硬币面值都超过了自己钱包里已有硬币的总面额，那么选择剩余的所有硬币中面额最小的一个。
  sum += coins[index]; // 加到手中总数中
  coins.erase(coins.begin() + index); // 拿走
}

int main()
{
  int n = 0;
  cin >> n;
  vector <long long> coins(n);
  for (auto &x: coins)
    cin >> x;
  // vector <long long> F, B;
  vector <vector <long long> > players(2);
  // int currentPlayer = 0;
  // // long long F_sum, B_sum, F_larger, B_larger = 0;

  // while (!coins.empty()) { // 判断当桌面上硬币个数不为空时执行

  //   // 法一
  //   // F_sum = 0;
  //   // B_sum = 0;
  //   // F_larger = 0;
  //   // B_larger = 0;

  //   // 法二
  //   auto &player = players[currentPlayer]; // 此处必须用&以保证是取的players中的vector, 否则会新定义一个vector
  //   currentPlayer = (currentPlayer + 1) % 2; // 使currentPlayer的数值01循环

  //   long long p_sum = 0;
  //   int p_larger = 0;
  //   // if (coins.size() > 0) { // 判断桌上是否还有牌
  //   for (auto &x: player)
  //     p_sum += x; // 计算F手中的总面额
  //   for (int i = 0; i < (int)coins.size(); i++) { // 依次检查桌上的牌
  //     if (p_sum >= coins[i]) { // 其中一张不超过总面额
  //       p_larger++; // 记录能拿的小牌数量
  //       int index_0 = -1; // 设置变量代表抽/没抽到
  //       for (int k = 0; k < (int)coins.size(); k++) { // 遍历amount数组
  //         if ((index_0 == -1 || coins[k] >= coins[index_0]) && p_sum >= coins[k]) // 在保证检查接下来的一张牌时F_sum始终最大的前提下寻找能拿的最大值
  //           index_0 = k; // 如果这张合适则换成这张
  //       }
  //       player.push_back(coins[index_0]); // 拿牌
  //       coins.erase(coins.begin()+index_0); // 从桌上拿走牌
  //       break; // F结束
  //       }
  //     }
  //   if (p_larger == 0) { // 当且仅当一个比手中总面额小的数都没有时
  //     int index = -1; // 抽/没抽
  //     for (int j = 0; j < (int)coins.size(); j++) { // 遍历amount数组
  //       if (index == -1 || coins[j] <= coins[index]) // 寻找面额最小的一个
  //         index = j; // 如果这张合适则换成这张
  //     }
  //     player.push_back(coins[index]); // 拿牌
  //     coins.erase(coins.begin()+index); // 从桌上拿走牌
  //   }
  // }
  
    /* 法一续
    // else
    //   break; // 桌上没有硬币则游戏结束
    // // Farmer John
    // // Bessie
    // if (coins.size() > 0) {
    //   for (auto &x: B)
    //     B_sum += x; // B手中的总面额
    //   for (int i = 0; i < (int)coins.size(); i++) {
    //     if (B_sum >= coins[i]) {
    //       B_larger++;
    //       int index_0 = -1;
    //       for (int k = 0; k < (int)coins.size(); k++) {
    //         if ((index_0 == -1 || coins[k] >= coins[index_0]) && B_sum >= coins[k])
    //           index_0 = k;
    //       }
    //       B.push_back(coins[index_0]);
    //       coins.erase(coins.begin()+index_0);
    //       break;
    //     }
    //   }
    //   if (B_larger == 0) {
    //     int index = -1;
    //     for (int j = 0; j < (int)coins.size(); j++) {
    //       if (index == -1 || coins[j] <= coins[index])
    //         index = j;
    //     }
    //     B.push_back(coins[index]);
    //     coins.erase(coins.begin()+index);
    //   }
    // }
    // else
    //   break;

  // F_sum = 0;
  // B_sum = 0;
  // for (auto &x: F)
  //   F_sum += x;
  // for (auto &x: B)
  //   B_sum += x;
  // cout << F_sum << " " << B_sum;
  */

  // 法三
  long long a = 0, b = 0;
  while (!coins.empty()) {
    getCoin(coins, a);
    if (coins.empty()) break;
    getCoin(coins, b);
  }
  // for (auto &player: players) {
  //   long long sum = 0;
  //   for (auto &x: player)
  //     sum += x;
  //   cout << sum << " ";
  // }
  cout << a << " " << b << endl;

  return 0;
}