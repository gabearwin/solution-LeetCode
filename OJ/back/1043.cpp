#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
char monthName[13][20]={
    "",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};
char weekName[7][20]={
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};
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
    char s[20];
    while (scanf("%d%s%d",&d,s,&y)!=EOF){
        for(m=1;m<13;m++){
            if(strcmp(s,monthName[m])==0) break;
        }
        int days=buf[y][m][d]-buf[2017][2][27];
        days+=1;
        puts(weekName[(days%7+7)%7]);
    }
    return 0;
}
