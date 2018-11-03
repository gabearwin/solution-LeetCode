#include<stdio.h>
#define OFFSET 500000
int main(){
    int n,m,i,a;
    while(scanf("%d %d",&n,&m)!=EOF){
        int hash[1000001]={0};
        for(i=1;i<=n;i++){
            scanf("%d",&a);
            hash[a+OFFSET]=1;
        }
        for(i=500000;i>=-500000;i--){
            if(hash[i+OFFSET]==1){
                printf("%d",i);
                m--;
                if(m!=0){printf(" ");}
                else{printf("\n");break;}
            }
        }
    }
    return 0;
}
