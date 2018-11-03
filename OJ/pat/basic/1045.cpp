#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100000;
int a[maxn],b[maxn],c[maxn],d[maxn];
int main(){
    int n;
    cin>>n;
    int M=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
        if(a[i]>M) M=a[i];
        c[i]=M;
    }
    sort(b,b+n);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]==b[i]&&a[i]>=c[i]){
            d[cnt++]=b[i];
        }
    }
    cout<<cnt<<endl;
    int first=1;
    for(int i=0;i<cnt;i++){
        if(first==1) {cout<<d[i];first=0;}
        else cout<<' '<<d[i];
    }
    cout<<endl;
    return 0;
}
