#include<stdio.h>
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int flag=1;
        printf("%d =",n);
        while(flag){
            flag=0;
            for(int i=2;i<=n/2;i++){
                if(n%i==0){
                    printf(" %d *",i);
                    n=n/i;
                    flag=1;
                    break;
                }
            }
        }
        printf(" %d\n",n);
    }
    return 0;
}
