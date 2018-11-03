#include<stdio.h>
int main(){
    int n;
    long long int a[91]={0,1,2};
    for(int i=3;i<91;i++) a[i]=a[i-1]+a[i-2];
    while(scanf("%d",&n)!=EOF){
        printf("%lld\n",a[n]);
    }
}
