#include<stdio.h>
#include<stdlib.h>
#define ISYEAP(x) ((x%4==0)&&(x%100!=0))||(x%400==0)?1:0
int dayOfMonth[13][2]={
    0,0,
    31,31,
    28,29,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31
};
struct Date{
    int Day,Month,Year;
    void nextDay(){
        Day++;
        if(Day>dayOfMonth[Month][ISYEAP(Year)]){
            Day=1;
            Month++;
            if(Month>12){
                Month=1;
                Year++;
            }
        }
    }
};
int buf[5001][13][32];
int main(){
    Date tmp;
    int cnt=0;
    tmp.Day=1;
    tmp.Month=1;
    tmp.Year=0;
    while(tmp.Year!=5001){
        buf[tmp.Year][tmp.Month][tmp.Day]=cnt;
        tmp.nextDay();
        cnt++;
    }
    int y,m,d;
    while(scanf("%d%d%d",&y,&m,&d)!=EOF){
        printf("%d\n",abs(buf[y][m][d]-buf[y][1][1])+1);
    }
    return 0;
}
