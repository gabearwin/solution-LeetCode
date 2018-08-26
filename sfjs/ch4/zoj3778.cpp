#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int T,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        int k,sum=0,maxn=0;
        while(n--){
            cin>>k;
            sum+=k;
            maxn=max(maxn,k);
        }
        int ans=ceil(sum*1.0/m);
        cout<<max(ans,maxn)<<endl;
    }
    return 0;
}
