#include<stdio.h>
int main(){
    int n,r;
    while(scanf("%d %d",&n,&r)!=EOF){
        int cnt=0;
        while(n!=0){
            if(n%r==1) cnt++;
            n=n/r;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
