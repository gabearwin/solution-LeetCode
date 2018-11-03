#include<stdio.h>
#define max 500005
int primesize,prime[max];
bool mark[max];
void init(){
    for(int i=0;i<max;i++) mark[i]=false;
    primesize=0;
    for(int i=2;i<max;i++){
        if(!mark[i]){
            prime[primesize++]=i;
            for(int j=i;j<max;j=j+i) mark[j]=true;
        }
    }
}
int main(){
    init();
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n>=1) printf("%d\n",prime[n-1]);
    }
    return 0;
}
