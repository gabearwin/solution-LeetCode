#include<stdio.h>
int max(int x,int y) {return x>y?x:y; }
int dp[26],lis[26];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){scanf("%d",&lis[i]); }
        for(int i=0;i<n;i++){
            int dist=1;
            for(int j=0;j<i;j++){
                if(lis[j]>=lis[i]) dist=max(dist,dp[j]+1);
            }
            dp[i]=dist;
        }
        int ans=1;
        for(int i=0;i<n;i++) ans=max(ans,dp[i]);
        printf("%d\n",ans);
    }
    return 0;
}
