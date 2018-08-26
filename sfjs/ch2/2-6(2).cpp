#include<stdio.h>
#include<string.h>
int main(){
    for(int i=123;i<=329;i++){
        int temp=i*1000000+i*2*1000+i*3;
        char s[10];
        sprintf(s,"%d",temp);
        int j=0;
        for(int k='1';k<='9';memchr(s,k++,9)&&j++);
        if(j==9)
            printf("%d %d %d\n",i,i*2,i*3);
    }
    return 0;
}
