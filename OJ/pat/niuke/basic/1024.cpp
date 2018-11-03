#include<stdio.h>
int main(){
    int n;
    long long int a[31]={0,1};
    for(int i=2;i<31;i++) a[i]=(a[i-1]+1)*2;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        printf("%lld\n",a[n]);
    }
    return 0;
}
