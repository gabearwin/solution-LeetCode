#include<stdio.h>
int main(){
    int n;
    long long int a[21]={0,0,1,2};
    for(int i=4;i<21;i++){
        a[i]=(a[i-1]+a[i-2])*(i-1);
    }
    while(scanf("%d",&n)!=EOF){
        printf("%lld\n",a[n]);
    }
    return 0;
}
