#include<stdio.h>
int rt(int a,int b){
    if(a!=b) return a<b;
    return 0;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int a,b,c=0;
        scanf("%d%d",&a,&b);
        c=rt(a,b);
        printf("%d\n",c);
    }
    return 0;
}
