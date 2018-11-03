/*#include<stdio.h>
int ans;
int fun(int i,int n){
    if(i>n) return ans;
    ans++;
    fun(2*i,n);
    fun(2*i+1,n);
}
int main(){
    int n,m;
    while(scanf("%d%d",&m,&n)!=EOF){
        if(n==0&&m==0) break;
        ans=0;
        ans=fun(m,n);
        printf("%d\n",ans);
    }
    return 0;
}*/
#include<stdio.h>
#include<math.h>
int main(){
    int n,m;
    while(scanf("%d%d",&m,&n)!=EOF){
        if(n==0&&m==0) break;
        int ans=1,i=0,root=m;
        if(m==n) {printf("1\n");continue;}
        if(m>n) {printf("0\n");continue;}
        while((2*m+1)<=n){
            i++;
            ans+=pow(2,i);

            m=2*m+1;
        }
        int tmp=root*pow(2,i+1);
        if(tmp<=n) ans+=n-tmp+1;
        printf("%d\n",ans);
    }
}
