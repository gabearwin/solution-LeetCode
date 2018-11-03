#include<iostream>
using namespace std;
void myswap(int a[],int s,int e){
    int mid=(s+e)/2;
    for(int i=s;i<=mid;i++){
        swap(a[i],a[s+e-i]);
    }
}
int main(){
    int n,m,a[100];
    cin>>n>>m;
    m=m%n;
    for(int i=0;i<n;i++) cin>>a[i];
    myswap(a,0,n-m-1);//以下三行，注意其思想
    myswap(a,n-m,n-1);
    myswap(a,0,n-1);
    int first=1;
    for(int i=0;i<n;i++){
        if(first) {cout<<a[i];first=0; }
        else cout<<' '<<a[i];
    }
    cout<<endl;
    return 0;
}
