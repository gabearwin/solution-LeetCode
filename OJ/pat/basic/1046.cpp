#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a1,a2,b1,b2,cnt1=0,cnt2=0;
    while(n--){
        cin>>a1>>a2>>b1>>b2;
        if(a2!=b2){
            if(a1+b1==a2) cnt2++;
            if(a1+b1==b2) cnt1++;
        }
    }
    cout<<cnt1<<' '<<cnt2;
    return 0;
}
