#include<iostream>
using namespace std;
const int maxn=100000;
int a[maxn],lmax[maxn],rmin[maxn];
int main(){
    int n;
    cin>>n;
    int M=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>M) M=a[i];
        lmax[i]=M;
    }
    int m=a[n-1];
    for(int i=n-1;i>=0;i--){
        if(a[i]<m) m=a[i];
        rmin[i]=m;
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]==lmax[i]&&a[i]==rmin[i]){
            cnt++;
        }else{
            a[i]=0;
        }
    }
    cout<<cnt<<endl;
    int first=1;
    for(int i=0;i<n;i++){
        if(a[i]){
            if(first==1) {cout<<a[i];first=0;}
            else cout<<' '<<a[i];
        }
    }
    cout<<endl;
    return 0;
}
