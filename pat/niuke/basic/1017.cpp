#include<stdio.h>
int main(){
    int n,r;
    while(scanf("%d %d",&n,&r)!=EOF){
        char k[1000];
        int i=0;
        while(n!=0){
            //k[i++]=n%r;
            if(n%r>=0&&n%r<=9) k[i++]=n%r+'0';
            if(n%r>=10) k[i++]=n%r-10+'A';
            n=n/r;
        }
        for(int j=i-1;j>=0;j--){
            printf("%c",k[j]);
        }
        printf("\n");
    }
    return 0;
}
