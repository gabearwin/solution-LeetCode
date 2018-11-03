#include<stdio.h>
int main(){
    int n,r;
    while(scanf("%d%d",&n,&r)!=EOF){
        int sum=0;
        while(n!=0){
            sum+=n%r;
            n=n/r;
        }
        char k[1000];
        int i=0;
        while(sum!=0){
            if(sum%r<10) k[i++]=sum%r+'0';
            else k[i++]=sum%r-10+'A';
            sum=sum/r;
        }
        for(int j=i-1;j>=0;j--)
            printf("%c",k[j]);
        printf("\n");
    }
    return 0;
}
