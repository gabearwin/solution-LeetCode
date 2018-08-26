#include<stdio.h>
#define max 1000000
bool mark[max];
int prime[max],primesize;
void init(int n){
    primesize=0;
    for(int i=0;i<=n;i++) mark[i]=false;
    for(int i=2;i<=n;i++){
        if(!mark[i]){
            prime[primesize++]=i;
            for(int j=i;j<=n;j+=i) mark[j]=true;
        }
    }
}
int main(){

    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        init(n);
        int ans=0;
        for(int i=0;prime[i]<=n/2;i++){
            int j=primesize;
            while(j--){//注意这里直接j减一了？？？
                if(prime[j]+prime[i]<n) break;
                if(prime[j]+prime[i]==n){ans++;break;}
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

