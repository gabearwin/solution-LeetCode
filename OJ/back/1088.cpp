#include<stdio.h>
int main(){
    int t[10001]={0};
    int i,L,M,a,b,j;
    while(scanf("%d%d",&L,&M)!=EOF){
        for(i=0;i<=L;i++){t[i]=1;}
        L=L+1;
        for(i=1;i<=M;i++){
            scanf("%d%d",&a,&b);
            for(j=a;j<=b;j++){
                if(t[j]!=0){
                    t[j]=0;
                    L--;
                }
            }
        }
        printf("%d\n",L);
    }
    return 0;
}
