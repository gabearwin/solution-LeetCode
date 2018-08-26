#include<stdio.h>
int maxnum;
char find_max(int a,int b,int c,int d){
    maxnum=a;
    if(b>maxnum) maxnum=b;
    if(c>maxnum) maxnum=c;
    if(d>maxnum) maxnum=d;
    if(maxnum==a) return 'A';
    if(maxnum==b) return 'C';
    if(maxnum==c) return 'G';
    if(maxnum==d) return 'T';
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int m,n,error=0;
        scanf("%d%d",&m,&n);
        char maps[50][1000];
        for(int i=0;i<m;i++){
            scanf("%s",maps[i]);
        }
        for(int j=0;j<n;j++){
            int count1=0,count2=0,count3=0,count4=0;
            for(int i=0;i<m;i++){
                if(maps[i][j]=='A') count1++;
                else if(maps[i][j]=='C') count2++;
                else if(maps[i][j]=='G') count3++;
                else if(maps[i][j]=='T') count4++;
            }
            char common=find_max(count1,count2,count3,count4);
            error+=m-maxnum;
            printf("%c",common);
        }
        printf("\n%d\n",error);
    }
    return 0;
}
