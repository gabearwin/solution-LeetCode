#include<iostream>
using namespace std;
int main(){
    long long int a,b,c;
    int k,d[30]={0},cnt=0;
    cin>>a>>b>>k;
    c=a+b;
    if(c==0) {cout<<0<<endl;return 0;}
    while(c!=0){
        d[cnt++]=c%k;
        c=c/k;
    }
    for(int i=cnt-1;i>=0;i--) cout<<d[i];
    cout<<endl;
    return 0;
}
