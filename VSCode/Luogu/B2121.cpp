#include <iostream>
#include <string.h>
using namespace std;

int main()
{
  // 法一
  // char sentence[20000];
  // cin.getline(sentence, 20000);
  // char delimiter[] = " ,.";
  // char copy1[20000];
  // char copy2[20000];
  // char copy3[20000];
  // memcpy(copy1, sentence, sizeof(sentence));
  // memcpy(copy2, sentence, sizeof(sentence));
  // memcpy(copy3, sentence, sizeof(sentence));

  // char *token = strtok(sentence, delimiter);
  // int max = 0;
  // while (token) {
  //   // cout << token << endl;
  //   int len = (int)strlen(token);
  //   if (len > max) {
  //     max = len;
  //   }
  //   token = strtok(NULL, delimiter);
  // }
  
  // token = strtok(copy1, delimiter);
  // while (token) {
  //   int len = (int)strlen(token);
  //   if (len == max) {
  //     cout << token;
  //     break;
  //   }
  //   token = strtok(NULL, delimiter);
  // }
  // cout << endl;

  // token = strtok(copy2, delimiter);
  // int min = 100;
  // while (token) {
  //   // cout << token << endl;
  //   int len = (int)strlen(token);
  //   if (len < min) {
  //     min = len;
  //   }
  //   token = strtok(NULL, delimiter);
  // }
  // if (min < 1) min++;
  // token = strtok(copy3, delimiter);
  // while (token) {
  //   int len = (int)strlen(token);
  //   if (len == min) {
  //     cout << token;
  //     break;
  //   }
  //   token = strtok(NULL, delimiter);
  // }

  
  // 法二
  char str[20000];
  cin.getline(str, 20000);
  char delimiter[] = " ,.";
  auto token = strtok(str, delimiter);
  char shortest[101], longest[101];
  strcpy(shortest, token);
  strcpy(longest, token);
  while (token) {
    if (strlen(token) < strlen(shortest))
      strcpy(shortest, token);
    if (strlen(token) > strlen(longest))
      strcpy(longest, token);
    token = strtok(NULL, delimiter);
  }
  cout << longest << endl << shortest;

  return 0;
}