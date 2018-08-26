#include<stdio.h>
int main(){
    int date[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int y,m,d,day=0,i;
    while(scanf("%d%d%d",&y,&m,&d)!=EOF){
        if(y%4==0&&y%100!=0||y%400==0) date[2]=29;
        else date[2]=28;
        day=0;
        for(i=1;i<m;i++) day+=date[i];
        day+=d;
        printf("%d\n",day);
    }
}
