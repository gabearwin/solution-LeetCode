#include<stdio.h>
#include<string.h>
int main(){
    char s[10000];
    while(gets(s)){
        for(int i=0;i<strlen(s);i++){
            if(s[i]>='A'&&s[i]<='E') s[i]+=21;
            else if(s[i]>='F'&&s[i]<='Z') s[i]-=5;
        }
        for(int i=0;i<strlen(s);i++){
            printf("%c",s[i]);
        }
        printf("\n");
    }
    return 0;
}
