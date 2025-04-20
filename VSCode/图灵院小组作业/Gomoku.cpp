#include <iostream>
using namespace std;

//C/C++:
// -------------------- 数据设计 --------------------
/*
    棋盘:
        map[i][j]表示坐标(i,j)的值
        0表示空地
        1表示黑子
        2表示白子
    如: map[3][6] = 1  表示(3,6)的位置是黑子
*/
int map[19][19];

// 表示当前回合数  偶数表示黑棋落子  奇数表示白棋落子
// 如: flag = 20 表示当前是第[20]次落子  由黑方落子
int flag;


// -------------------- 数据设计 --------------------


// -------------------- service --------------------
/*
    负责人: 张三
    功能: init: 初始化游戏数据
        将棋盘的值初始化为0
        当前回合设为黑棋(flag设为0)
    参数: void
    返回值: void
*/
void init();

/*
    *难点1
    负责人: 张三
    功能: isWin: 根据传入的坐标(map对应位置)和flag值 判断落点后是否获胜
    参数:
        x: 当前回合落子的x坐标
        y: 当前回合落子的y坐标
    返回值:
        0表示没有获胜
        1表示黑子胜利
        2表示白子胜利
*/
int isWin(int x, int y);

/*
    负责人: 张三
    功能: playerMove: 在指定位置落子
        如果map[x][y]是空地 则修改map[x][y]的值:改为相应颜色(flag对应颜色)        否则不操作
    参数:
        x: 当前回合落子的x坐标
        y: 当前回合落子的y坐标
    返回值:
        0表示落子失败 (棋盘已经有子)
        1表示落子成功

*/
int playerMove(int x, int y);
// -------------------- service --------------------



// -------------------- view --------------------
/*
    负责人: 张三
    功能: menuView: 展示选项, 玩家可以在这里选择进入游戏, 进入设置或退出游戏
        进入游戏: 调用游戏界面函数gameView();
        进入设置: 敬请期待...
        退出游戏: 调用exit(0);
    参数: void
    返回值: void
*/
void menuView();

/*
    负责人: 张三
    功能: gameView_ShowMap: 根据map数组 打印游戏棋盘
    参数: void
    返回值: void
*/
void gameView_ShowMap();

/*
    负责人: 张三
    功能: winView: 根据flag的值  打印游戏胜利界面  用户可以按任意键回到主菜单
    参数: void
    返回值: void
*/
void winView();

/*
    *难点2
    负责人: 张三
    功能: gameView: 游戏界面整合
        初始化游戏数据(调用函数init())
        while(1){
            打印游戏界面(调用函数gameView_ShowMap())
            接收玩家坐标输入

            落子(调用落子函数playerMove())
                (如果落子失败 重新开始循环)

            判断游戏是否胜利(调用胜利判断函数isWin())
                (如果游戏胜利 调用胜利界面函数 然后结束当前界面)
            切换玩家(修改flag值)
        }
    参数: void
    返回值: void
*/
void gameView();
// -------------------- view --------------------

int main()
{
    menuView();
    return 0;
}

void init(){
    //在此处完成代码
    for (auto &x: map) {
      for (auto &y: x)
        y = 0;
    }
    flag = 0;
}

int isWin(int x, int y){
    //在此处完成代码

    // 存储(x, y)所在的"米"字型棋盘样式
    int judge[4][9] = {0};
    // 左右方向
    for (int i = -4; i <= 4; i++) {
      if (map[x+i][y] == 1 || map[x+i][y] == 2)
        judge[0][i+4] = map[x+i][y];
    }
    // 上下方向
    for (int i = -4; i <= 4; i++) {
      if (map[x][y+i] == 1 || map[x][y+i] == 2)
        judge[1][i+4] = map[x][y+i];
    }
    // 主对角线方向
    for (int i = -4; i <= 4; i++) {
      if (map[x+i][y+i] == 1 || map[x+i][y+i] == 2)
        judge[2][i+4] = map[x+i][y+i];
    }
    // 副对角线方向
    for (int i = -4; i <= 4; i++) {
      if (map[x+i][y-i] == 1 || map[x+i][y-i] == 2)
        judge[3][i+4] = map[x+i][y-i];
    }
    // 测试
    // for (auto &x: judge) {
    //   for (auto &y: x) {
    //     cout << y << " ";
    //   }
    //   cout << endl;
    // }

    // 进行判断
    int count_1 = 0, count_2 = 0;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 9 && count_1 < 5 && count_2 < 5; j++) {
        if (judge[i][j] == 1) {
          count_1++;
          count_2 = 0;
        }
        else if (judge[i][j] == 2) {
          count_1 = 0;
          count_2++;
        }
        else {
          count_1 = 0;
          count_2 = 0;
        }
      }
      if (count_1 >= 5) return 1;
      else if (count_2 >= 5) return 2;
      else count_1 = 0, count_2 = 0;
    }
    return 0;
}

int playerMove(int x, int y){
    //在此处完成代码
    if (map[x][y] == 0) {
      map[x][y] = (flag%2 == 0 ? 2 : 1);
      return 1;
    }
    else
      return 0;
}

void menuView(){
    //在此处完成代码
    cout << "---------------" << endl;
    cout << "|   *菜单*    |" << endl;
    cout << "| 1.进入游戏  |" << endl;
    cout << "| 2.进入设置  |" << endl;
    cout << "| 3.退出游戏  |" << endl;
    cout << "---------------" << endl;
    int menu;
    cin >> menu;
    if (menu == 1) {
      gameView();
    }
    else if (menu == 2) {
      cout << "敬请期待..." << endl;
    }
    else if (menu == 3) {
      exit(0);
    }
}

void gameView_ShowMap(){
    //在此处完成代码
    cout << "   ";
    for (int i = 0; i < 19; i++)
      cout << i << " ";
    cout << endl;
    int i = 0;
    for (auto &x: map) {
      printf("%2d ", i);
      for (auto &y: x) {
        if (y == 0) {
          cout << "  ";
        }
        else if (y == 1) {
          cout << "○ "; // 黑字
        }
        else if (y == 2) {
          cout << "● "; // 白子
        }
      }
      i++;
      cout << endl;
    }
}

void winView(){
    //在此处完成代码
    if (flag%2 == 0) {
      cout << "恭喜黑子获胜!╰(*°▽°*)╯";
    }
    else {
      cout << "恭喜白子获胜!╰(*°▽°*)╯";
    }
}

void gameView(){
    //在此处完成代码
    init();

    while(1) {
      gameView_ShowMap();
      int x, y;
      cin >> x >> y;
      if (playerMove(x, y) != 0) {
        playerMove(x, y);
        flag++;
      }
      else continue;
      if (isWin(x, y)) {
        gameView_ShowMap();
        winView();
        break;
      }
    }
}