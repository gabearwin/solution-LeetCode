#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100002;
int a[maxn],n,p;
int main(){
    cin>>n>>p;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int ans=1,m,M;
    for(int i=0;i<n;i++){
        m=a[i];
        for(int j=i+ans;j<n;j++){
            M=a[j];
            if(M*1.0/m<=p){
                ans=max(ans,j-i+1);
            }else break;
        }
    }
    cout<<ans;
    return 0;
}
