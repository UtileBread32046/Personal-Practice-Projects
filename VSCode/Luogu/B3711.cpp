#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int T = 0;
  vector <int> num;
  cin >> T;

  while (T--) {
    long long n = 0;
    cin >> n;
    long long n2 = n;
    bool beFound = false;

    while (n > 0) {
      num.insert(num.begin(), n%10);
      n /= 10;
    }

    // for (auto &x: num)
    //   cout << x;

    if (n2%4 == 0) {
      beFound = true;
    }

    for (int i = 0; i < (int)num.size() && !beFound; i++) {
      for (int j = i+1; j <= (int)num.size() && !beFound; j++) {
        auto temp = num; // 当不加上取地址符&时, 设置的新动态数组不会影响原数组中的数据
        temp.erase(temp.begin()+i, temp.begin()+j);
        long long sum = 0;
        if (temp.empty())
          continue;

        for (auto x: temp) {
          sum *= 10;
          sum += x;
        }

        // cout << sum << endl;
        if (sum % 4 == 0) {
          beFound = true;
        }
        else {
          continue;
        }
      }
    }

    cout << (beFound ? "Yes" : "No") << endl;
    num.clear();
  }
  return 0;
}