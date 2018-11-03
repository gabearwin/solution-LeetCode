#include<stdio.h>
bool mark[10001];
int prime[10000],primesize;
void init(){
    for(int i=0;i<10001;i++) mark[i]=false;
    primesize=0;
    for(int i=2;i<10001;i++){
        if(mark[i]==true) continue;
        prime[primesize++]=i;
        for(int j=i*i;j<10001;j=j+i) mark[j]=true;
    }
}
int main(){
    init();
    int n;
    while(scanf("%d",&n)!=EOF){
        bool isoutput=false;
        for(int i=0;i<primesize;i++){
            if(prime[i]<n&&prime[i]%10==1){
                if(!isoutput){
                    isoutput=true;
                    printf("%d",prime[i]);
                }
                else printf(" %d",prime[i]);
            }
        }
        if(isoutput==false) printf("-1\n");
        else printf("\n");
    }
}
