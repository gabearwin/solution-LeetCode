#include<stdio.h>
#include<math.h>
int main(){
    long long int m,n;
    while(scanf("%lld%lld",&m,&n)!=EOF){
        long long int ans;
        ans=m*n;
        if(m%2==1&&n%2==1) printf("%lld.41\n",ans);
        else printf("%lld.00\n",ans);
    }
    return 0;
}

