#include<stdio.h>
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int ans=0;
        while(n!=1){
            if(n%2==0) n=n/2;
            else n=(3*n+1)/2;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
