#include <iostream>
using namespace std;

int main()
{
  int m = 0;
  int t_bike, t_walk = 0;
  cin >> m;
  t_bike = t_bike + 27 + 23 + m/3.0;
  t_walk = t_walk + m/1.2;
  auto result = t_bike <=> t_walk;
  if (result < 0)
    puts("Bike");
  else if (result > 0)
    puts("Walk");
  else
    puts("All");

  return 0;
}