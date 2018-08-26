#include<stdio.h>
int main(){
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF){
        int i=0,j=0,a[100],b[100];
        while(m!=0){
            a[i++]=m%10;
            m=m/10;
        }
        while(n!=0){
            b[j++]=n%10;
            n=n/10;
        }
        int L1=i,L2=j,ans=0;
        for(i=0;i<L1;i++){
            for(j=0;j<L2;j++)
                ans+=a[i]*b[j];
        }
        printf("%d\n",ans);
    }
    return 0;
}
