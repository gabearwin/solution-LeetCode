#include<stdio.h>
bool run(int n){
    return (n%4==0&&n%100!=0)||n%400==0?true:false;
}
int main(){
    int nian[8001]={0,92};
    for(int i=2;i<8001;i++){
        if(run(i+2000-1)) nian[i]=nian[i-1]+366;
        else nian[i]=nian[i-1]+365;
    }
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==2000) {printf("10\n");continue;}
        int yue[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
        int days=0,flag=1;;
        days=days+nian[n-2000];
        if(run(n)) yue[2]=29;
        for(int i=1;i<=12;i++){
            days+=yue[i-1];
            if(days%7==0) {
                if(flag==1){
                    printf("%d",i);
                    flag=0;
                }else{
                    printf(" %d",i);
                }
            }
        }
        if(flag==1) printf("Luck\n");
        else printf("\n");
    }
    return 0;
}
