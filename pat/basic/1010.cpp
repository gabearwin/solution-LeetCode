#include<iostream>
using namespace std;
int main(){
    int a,b,cnt=0;
    while(cin>>a>>b){
        cnt++;
        if(a*b!=0){
            if(cnt==1) cout<<a*b<<' '<<b-1;
            else cout<<' '<<a*b<<' '<<b-1;
        }
    }
    if(cnt==1) cout<<"0 0";
    return 0;
}
