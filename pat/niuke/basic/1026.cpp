#include<stdio.h>
int main(){
    int a,b,n;
    while(scanf("%d%d%d",&a,&b,&n)!=EOF){
        a=a*10;
        int i=0,k[1001]={0};
        while(a!=0){
            if(i==n) break;
            if(a/b==0){
                a=a*10;
                k[i++]=0;
            }else{
                k[i++]=a/b;
                a=a%b*10;
            }
        }
        printf("0.");
        for(int i=0;i<n;i++){
            printf("%d",k[i]);
        }
        printf("\n");
    }
    return 0;
}
