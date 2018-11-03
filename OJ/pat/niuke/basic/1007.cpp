#include<stdio.h>
int main(){
    int n;
    long long int a[56]={0,1,2,3};
    for(int i=4;i<56;i++) a[i]=a[i-1]+a[i-3];
    while(scanf("%d",&n)!=EOF){
        printf("%lld\n",a[n]);
    }
    return 0;
}
