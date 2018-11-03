#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    long long int a[10001]={0,1,2};
    for(int i=3;i<10001;i++) a[i]=a[i-1]+a[i-2];
    int x,y;
    for(int i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        printf("%lld\n",a[y-x]);
    }
    return 0;
}
