#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    double a[1001]={0.0};
    int k,n;
    double an;
    cin>>k;
    while(k--){
        cin>>n>>an;
        a[n]+=an;
    }
    cin>>k;
    while(k--){
        cin>>n>>an;
        a[n]+=an;
    }
    int ansk=0;
    for(int i=1000;i>=0;i--){
        if(a[i]!=0) ansk++;
    }
    cout<<ansk;
    for(int i=1000;i>=0;i--){
        if(a[i]!=0) printf(" %d %.1f",i,a[i]);
    }
    return 0;
}
