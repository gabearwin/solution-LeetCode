#include<iostream>
#include<cstring>
using namespace std;
const int maxn=100001;
int a[maxn],b[maxn];
int main(){
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    int n,m,k;
    cin>>n;
    for(int i=0;i<n;i++) {cin>>m;a[m]++;}
    cin>>k;
    for(int i=0;i<k;i++) cin>>b[i];
    for(int i=0;i<k;i++){
        if(i==0) cout<<a[b[0]];
        else cout<<' '<<a[b[i]];
    }
    return 0;
}
