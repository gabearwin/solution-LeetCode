#include<stdio.h>
#include<string.h>
#define maxn 105

// ��״��s�ı�ʾ��i�Ƿ�ȱ�ʾ��ans���ֵ���С
bool less(const char* s, int i, int ans) {
  int n = strlen(s);
  for(int j = 0; j < n; j++)
    if(s[(i+j)%n] != s[(ans+j)%n])
      return s[(i+j)%n] < s[(ans+j)%n] ? true : false;
  return false; // ���
}

int main() {
  int T;
  char s[maxn];
  scanf("%d", &T);
  while(T--) {
    scanf("%s", s);
    int ans = 0;
    int n = strlen(s);
    for(int i = 1; i < n; i++)
      if(less(s, i, ans)) ans = i;
    for(int i = 0; i < n; i++)
      putchar(s[(i+ans)%n]);
    putchar('\n');
  }
  return 0;
}
