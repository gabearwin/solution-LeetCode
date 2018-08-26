#include<stdio.h>
int main(){
    int i,n,b[101]={0};
    long long int a[10001]={1,2};
    for(i=2;i<10001;i++) a[i]=(a[i-1]%10000+a[i-2]%10000)%10000;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){scanf("%d",&b[i]); }
        for(i=0;i<n;i++)
        printf("%04lld",a[b[i]-1]);
        printf("\n");
    }
}
