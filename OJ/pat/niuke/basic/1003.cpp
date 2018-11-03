#include<stdio.h>
#include<math.h>
int main(){
    int n;
    long long a[91]={1,2};
    for(int i=2;i<91;i++){a[i]=a[i-1]+a[i-2];}
    while(scanf("%d",&n)!=EOF){
        printf("%lld\n",a[n-1]);
    }
    return 0;
}
