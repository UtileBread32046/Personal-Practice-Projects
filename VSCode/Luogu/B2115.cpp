#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;

int main()
{
  char password[100000];
  cin.getline(password, 100000);
  for (int i = 0; i < (int)strlen(password); i++) {
    // 法一  
    // if (isalpha(password[i])) {
    //   if (password[i] == 'a')
    //     password[i] = 'z';
    //   else if (password[i] == 'A')
    //     password[i] = 'Z';
    //   else
    //   //     password[i]--;
    // }
    
    // 法二
    if (isupper(password[i]))
      password[i] = (password[i] - 'A' + 25) % 26 + 'A';
    if (islower(password[i]))
      password[i] = (password[i] - 'a' + 25) % 26 + 'a';
  }
  cout << password;

  return 0;
}