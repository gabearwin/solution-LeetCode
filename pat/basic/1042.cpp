#include<iostream>
#include<cstdio>
#include<ctype.h>
using namespace std;
int main(){
    char c;
    int a[128]={0};
    while((c=getchar())!='\n'){
        if(isalpha(c)){
            a[tolower(c)]++;
        }
    }
    int m=97;
    for(int i=97;i<=123;i++){
        if(a[i]>a[m]) m=i;
    }
    printf("%c %d",m,a[m]);
    return 0;
}
