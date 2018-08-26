#include<stdio.h>
int main(){
    int m;
    long long a,b;
    while(scanf("%d",&m)!=EOF){
        if(m==0) break;
        scanf("%lld%lld",&a,&b);
        int buf[100],i=0;
        long long c=a+b;
        if(c){
        while(c){
            buf[i++]=c%m;
            c=c/m;
        }
        for(int j=i-1;j>0;j--){
            printf("%d",buf[j]);
        }
        printf("%d\n",buf[0]);
        }
        else printf("0\n");
    }
    return 0;
}
