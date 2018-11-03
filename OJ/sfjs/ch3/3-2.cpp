#include<stdio.h>
#include<string.h>
int main(){
    char s[]="qwertyuiop[]\asdf";
    printf("%d\n%s\n",strlen(s),s);
    for(int i=0;i<strlen(s);i++)
        printf("%c\n",s[i]);
    return 0;
}
