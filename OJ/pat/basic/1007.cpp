#include<iostream>
#include<cmath>
using namespace std;
const int maxn=100002;
bool is_prime(int n){
    if(n<=1) return false;
    int m=floor(sqrt(n)+0.5);
    for(int i=2;i<=m;i++)
        if(n%i==0) return false;
    return true;
}
int main(){
    int n;
    while(cin>>n){
        int ans=0;
        for(int i=3;i<=n;i++){
            if(is_prime(i)==true&&is_prime(i-2)==true) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
