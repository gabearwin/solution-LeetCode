#include<iostream>
using namespace std;
int stair(int n){
    if( n == 0 )
        return 1;
    if( n == 1 )
        return 1;
    return stair( n-1 ) + stair( n-2 );
}
int main(){
    int n;
    while(cin>>n)
        cout<<stair(n)<<endl;
    return 0;
}
