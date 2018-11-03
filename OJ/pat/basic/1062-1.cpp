#include<cstdio>
#include<iostream>
using namespace std;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    int n1,m1,n2,m2,k;
    scanf("%d/%d %d/%d %d",&n1,&m1,&n2,&m2,&k);
    if(n1*m2>n2*m1){
        swap(n1,n2);
        swap(m1,m2);
    }
    int first=1;
    for(int t=n1*k/m1+1;t*m2<k*n2;t++){
        if(gcd(t,k)==1){
            if(first) {cout<<t<<'/'<<k;first=0;}
            else cout<<' '<<t<<'/'<<k;
        }
    }
    return 0;
}
