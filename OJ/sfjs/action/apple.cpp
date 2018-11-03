#include<iostream>
using namespace std;
int f(int m, int n){
    if( n==1 || m==0 )
        return 1;
    if( n > m )                 //盘子数n大于m
        return f(m,m);
    return f(m,n-1) + f(m-n,n); //当 n<=m 时的两种情况之和
}
int main(){
    int m,n;
    while(cin>>m>>n)
        cout<<f(m,n)<<endl;
    return 0;
}
