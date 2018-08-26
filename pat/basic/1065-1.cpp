#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=100002;
pair <int, int> a[maxn/2];
int b[maxn];
int main(){
    memset(b,0,sizeof(b));
    int n,m,mm;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    cin>>m;
    for(int i=0;i<m;i++) {cin>>mm;b[mm]=1;}
    int f,s;
    for(int i=0;i<n;i++){
        f=a[i].first,s=a[i].second;
        if(b[f]==1&&b[s]==1&&f==s) m--;
        else if(b[f]==1&&b[s]==1){
            b[f]=0,b[s]=0;
            m-=2;
        }
    }
    cout<<m<<endl;
    int first=0;
    for(int i=0;i<maxn;i++){
        if(b[i]==1){
            printf("%s%05d",first++?" ":"",i);
        }
    }
    return 0;
}
