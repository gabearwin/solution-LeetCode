#include<stdio.h>
int prime[100000]={0},primecnt=0;
bool num[100000]={false};
void init(){
    for(int i=2;i<100000;i++){
        if(num[i]) continue;
        prime[primecnt++]=i;
        for(int j=i*i;j<100000;j=j+i) num[j]=true;
    }
}
int main(){
    int n;
    init();
    while(scanf("%d",&n)!=EOF){
        int cnt=0;
        for(int i=0;prime[i+1]<=n;i++){
            if(prime[i+1]-prime[i]==2) cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
