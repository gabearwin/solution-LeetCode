#include<stdio.h>
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int m=n*n,flag=1;;
        while(n!=0){
            int tmp1=n%10;
            int tmp2=m%10;
            if(tmp1!=tmp2) {flag=0;break;}
            n=n/10;
            m=m/10;
        }
        if(flag==1) printf("Yes!\n");
        else printf("No!\n");
    }
    return 0;
}
