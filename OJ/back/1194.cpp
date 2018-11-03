#include<stdio.h>
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int i=0,a[100];
        do{
            a[i++]=n%8;
            n=n/8;
        }while(n);
        for(int j=i-1;j>=0;j--) printf("%d",a[j]);
        printf("\n");
    }
    return 0;
}
