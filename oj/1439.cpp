#include<stdio.h>
long long gcd(long long x,long long y){
    if(y==0) return x;
    else return gcd(y,x%y);
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        while(n--){
            int i=0,m,b;
            scanf("%d",&m);
            long long a[100];
            while(m--) {
                scanf("%d",&b);
                a[i++]=b;
            }
            long long ans=a[0];
            for(int j=0;j<i-1;j++)
                ans=(ans*a[j+1])/gcd(ans,a[j+1]);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
