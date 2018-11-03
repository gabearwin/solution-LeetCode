#include<stdio.h>
#include<string.h>
int num[10];
void countnum(int n){
    int a=n/1000,b=n%1000/100,c=n%100/10,d=n%10;
    if(a>0){num[a]++;num[b]++;num[c]++;num[d]++; }
    else if(b>0){num[b]++;num[c]++;num[d]++;}
    else if(c>0){num[c]++;num[d]++;}
    else num[d]++;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(num,0,sizeof(num));
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) countnum(i);
        for(int i=0;i<=8;i++) printf("%d ",num[i]);
        printf("%d\n",num[9]);
    }
    return 0;
}
