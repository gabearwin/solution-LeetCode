#include <stdio.h>
#include <string.h>

int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int IsLeapYear(int y){
    return (y % 4==0 && y%100 != 0 || y%400 == 0 ? 1:0);
}

int main(){
    int buf[2001][12][31];
     int d=0,m=0,y=0,cnt=0;//1000年1月1日
     while(y != 2001){
         buf[y][m][d]=cnt;
         cnt++;
         d++;
         if( m==1 ){
             if(IsLeapYear(y+1000)==1 && d==month[m]+1){
             d=0;
             m++;
             }
             else if(IsLeapYear(y+1000)==0 && d==month[m]){
             d=0;
             m++;
             }
         }
         else {
             if(d==month[m]){
             d=0;
             m++;
             }
             if(m==12) {m=0;y++;}
         }

     }

     int Y,D,mon=0;
     char M[50];
     //freopen("C:\\Users\\Administrator\\Desktop\\acm.txt","r",stdin);
     while( scanf("%d%s%d",&D,M,&Y) != EOF){
        if( strcmp(M,"January")==0 ) mon=0;
        else if( strcmp(M,"February")==0 ) mon=1;
        else if( strcmp(M,"March")==0 ) mon=2;
        else if( strcmp(M,"April")==0 ) mon=3;
        else if( strcmp(M,"May")==0) mon=4;
        else if( strcmp(M,"June")==0 ) mon=5;
        else if( strcmp(M,"July")==0 ) mon=6;
        else if( strcmp(M,"August")==0 ) mon=7;
        else if( strcmp(M,"September")==0 ) mon=8;
        else if( strcmp(M,"October")==0 ) mon=9;
        else if( strcmp(M,"November")==0 ) mon=9;
        else if( strcmp(M,"December")==0 ) mon=11;
        else ;
        int days=buf[Y-1000][mon][D-1]-buf[1017][1][26];//目标日期减去起始日期
        days=(days%7+7)%7+1;
        //printf("%d\n",days);
        switch(days){
        case 1:printf("Monday\n");break;
        case 2:printf("Tuesday\n");break;
        case 3:printf("Wednesday\n");break;
        case 4:printf("Thursday\n");break;
        case 5:printf("Friday\n");break;
        case 6:printf("Saturday\n");break;
        case 7:printf("Sunday\n");break;
        default:break;
        }

     }//while

return 0;

}
/**************************************************************
    Problem: 1043
    User: 汪适
    Language: C++
    Result: Accepted
    Time:10 ms
    Memory:3856 kb
****************************************************************/
