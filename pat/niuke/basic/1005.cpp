#include<stdio.h>
int main(){
    int n;
    long long int a[100001]={0};
    a[1]=1;
    a[2]=2;
    int fj,flag=0;
    for(int i=3;i<100001;i++){

        a[i]=(a[i-1]%1000000+a[i-2]%1000000)%1000000;
        if(a[i-1]%1000000+a[i-2]%1000000>999999&&flag==0){
            flag=1;
            fj=i;
        }
    }
    //printf("%d\n",fj);
    while(scanf("%d",&n)!=EOF){
        if(n<=fj) printf("%lld\n",a[n]);
        else printf("%06lld\n",a[n]);
    }
    return 0;
}
