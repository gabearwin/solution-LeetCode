#include<stdio.h>
int main(){
    int f,t;
    while(scanf("%d%d",&f,&t)!=EOF){
        long long a[81]={1,1},sum=0;
        for(int i=2;i<81;i++) a[i]=a[i-1]+a[i-2];
        for(int i=f-1;i<t;i++){
            sum+=a[i];
        }
        printf("%lld\n",sum);
    }
    return 0;
}
