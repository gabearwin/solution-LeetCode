#include<iostream>
using namespace std;
int f(int m, int n){
    if( n==1 || m==0 )
        return 1;
    if( n > m )                 //������n����m
        return f(m,m);
    return f(m,n-1) + f(m-n,n); //�� n<=m ʱ���������֮��
}
int main(){
    int m,n;
    while(cin>>m>>n)
        cout<<f(m,n)<<endl;
    return 0;
}
