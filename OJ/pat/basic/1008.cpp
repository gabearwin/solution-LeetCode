#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    m=m%n;
    int a[100];
    for(int i=0;i<n;i++) cin>>a[i];
    int first=1;
    for(int i=n-m;i<n;i++){
        if(first) {cout<<a[i];first=0;}
        else cout<<' '<<a[i];
    }
    for(int i=0;i<n-m;i++){
        if(first) {cout<<a[i];first=0;}
        else cout<<' '<<a[i];
    }
    cout<<endl;
    return 0;
}
