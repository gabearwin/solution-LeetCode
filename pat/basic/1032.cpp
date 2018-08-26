#include<iostream>
using namespace std;
const int maxn=100000;
int a[maxn];
int main(){
    int n;
    cin>>n;
    int id,score,ans=0;
    while(n--){
        cin>>id>>score;
        a[id]+=score;
    }
    for(int i=0;i<maxn;i++){
        if(a[i]>a[ans]) ans=i;
    }
    cout<<ans<<' '<<a[ans];
    return 0;
}
