#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    char c;
    cin>>n>>c;
//    cout<<ceil(n*1.0/2)<<endl;
    for(int i=0;i<ceil(n/2.0);i++){
        for(int j=0;j<n;j++){
            if(i==0||i==ceil(n/2.0)-1) cout<<c;
            else{
                if(j==0||j==n-1) cout<<c;
                else cout<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}
