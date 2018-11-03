#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
char month[][20]={"January", "February", "March", "April", "May", "June",
 "July", "August", "September", "October", "November", "December"};
int find_month(char m[]){
    for(int i=0;i<12;i++){
        if(strcmp(m,month[i])==0)
            return i+1;
    }
    return 0;
}
bool leap(int year){
    if((year%4==0&&year%100!=0)||year%400==0) return true;
    return false;
}
int main(){
    int T,day1,year1,day2,year2,kase=0;
    char temp1[20],temp2[20];
    scanf("%d",&T);
    while(T--){
        int cnt=0;
        scanf("%s %d, %d",temp1,&day1,&year1);
        scanf("%s %d, %d",temp2,&day2,&year2);
        int month1=find_month(temp1),month2=find_month(temp2);
        //printf("%d %d %d %d %d %d\n",year1,month1,day1,year2,month2,day2);
        if(leap(year1)){
            if(month1<=2) cnt++;
        }
        for(int i=year1+1;i<year2;i++){
            //printf("%d\n",leap(i));
            if(leap(i)) cnt++;
        }
        if(year2!=year1&&leap(year2)){
            if(month2>2) cnt++;
            else if(month2==2&&day2==29) cnt++;
        }
        printf("Case %d: %d\n",++kase,cnt);
    }
    return 0;
}
