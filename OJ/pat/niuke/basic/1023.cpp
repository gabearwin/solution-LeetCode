#include<stdio.h>
int main(){
    int n,m;
    long long int a[21]={0,0,1,2};
    for(int i=4;i<21;i++){
        a[i]=(a[i-1]+a[i-2])*(i-1);
    }
    while(scanf("%d%d",&n,&m)!=EOF){
        long long int jc1=1,jc2=1;
        for(int i=n;i>n-m;i--){
            jc1=jc1*i;
        }
        for(int i=1;i<=m;i++){
            jc2=jc2*i;
        }
        long long int ans;
        ans=jc1/jc2*a[m];
        printf("%lld\n",ans);
    }
    return 0;
}
