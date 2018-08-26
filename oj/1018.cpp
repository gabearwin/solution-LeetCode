#include<stdio.h>
int main(){
    int n,i,x;
    while(scanf("%d",&n)!=EOF&&n!=0){
        int hash[101]={0};
        for(i=1;i<=n;i++){
            scanf("%d",&x);
            hash[x]++;
        }
        scanf("%d",&x);
        printf("%d\n",hash[x]);
    }
    return 0;
}
