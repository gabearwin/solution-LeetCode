#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
bool leap(int year){
    if((year%4==0&&year%100!=0)||year%400==0) return true;
    return false;
}
int main(){
    int T,day1,year1,day2,year2,kase=0;
    char month1[20],month2[20];
    scanf("%d",&T);
    while(T--){
        scanf("%s %d, %d",month1,&day1,&year1);
        scanf("%s %d, %d",month2,&day2,&year2);
        int cnt=(year2/4-year2/100+year2/400)-(year1/4-year1/100+year1/400);
        if(leap(year1)){
            if(month1[0]=='J'&&month1[1]=='a'||month1[0]=='F') cnt++;
        }
        if(leap(year2)){
            if(month2[0]=='J'&&month2[1]=='a'||month2[0]=='F'&&day2<29) cnt--;
        }
        printf("Case %d: %d\n",++kase,cnt);
    }
    return 0;
}
