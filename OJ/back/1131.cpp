#include<stdio.h>
int max(int x,int y){return x>y?x:y; }
int lis[101],dp1[101],dp2[101];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){scanf("%d",&lis[i]); }
        for(int i=0;i<n;i++){
            int dist=1;
            for(int j=0;j<i;j++){
                if(lis[j]<lis[i]) dist=max(dist,dp1[j]+1);
            }
            dp1[i]=dist;
        }
        for(int i=n-1;i>=0;i--){
            int dist=1;
            for(int j=n-1;j>i;j--){
                if(lis[j]<lis[i]) dist=max(dist,dp2[j]+1);
            }
            dp2[i]=dist;
        }
        int ans=0;
        for(int i=0;i<n;i++) {dp1[i]+=dp2[i]-1;ans=max(ans,dp1[i]);}
        printf("%d\n",n-ans);
    }
    return 0;
}
