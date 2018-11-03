#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int main(){
    char s1[101],s2[101];
    while(scanf("%s%s",s1,s2)!=EOF){
        int L1=strlen(s1);
        int L2=strlen(s2);
        int dp[101][101];
        for(int i=0;i<=L1;i++) dp[i][0]=0;
        for(int j=0;j<=L2;j++) dp[0][j]=0;
        for(int i=1;i<=L1;i++){
            for(int j=1;j<=L2;j++){
                if(s1[i-1]!=s2[j-1]) dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                else dp[i][j]=dp[i-1][j-1]+1;
            }
        }
        printf("%d\n",dp[L1][L2]);
    }
    return 0;
}
