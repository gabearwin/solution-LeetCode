#include<iostream>
#include<cstring>
using namespace std;
const int maxn=110;
int friends[maxn][maxn];
int ans;
int make_friends(int n,int k){
    ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(friends[i][j]==0){
                int cnt=0;
                for(int t=0;t<n;t++){
                    if(friends[i][t]==1&&friends[j][t]==1)
                        cnt++;
                }
                if(cnt>=k){
                    friends[i][j]=1;
                    friends[j][i]=1;
                    ans++;
                    i=-1;
                    break;
                }
            }
        }
    }
    return ans;
}
int main(){
    int T,n,m,k,from,to;
    cin>>T;
    while(T--){
        memset(friends,0,sizeof(friends));
        cin>>n>>m>>k;
        while(m--){
            cin>>from>>to;
            friends[from][to]=1;
            friends[to][from]=1;
        }
        ans=make_friends(n,k);
        cout<<ans<<endl;
    }
    return 0;
}
