#include<stdio.h>
int main(){
    int date[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int y,n,i;
    while(scanf("%d%d",&y,&n)!=EOF){
        if(y%4==0&&y%100!=0||y%400==0) date[2]=29;
        else date[2]=28;
        for(i=1;i<13;i++){
            if(n<=date[i]) break;
            n-=date[i];
        }
        printf("%04d-%02d-%02d\n",y,i,n);
    }
}
