#include<cstdio>
#include<iostream>
using namespace std;
int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main(){
    long long int n1,m1,n2,m2,k;
    scanf("%d/%d %d/%d %d",&n1,&m1,&n2,&m2,&k);
    long long int gcd_3=gcd(gcd(m1,m2),k);
    n1=m2*k/gcd_3*n1,n2=m1*k/gcd_3*n2;
    long long int m=m1*m2*k/gcd_3;
    if(n1>n2) swap(n1,n2);
    long long int first=1,gcd_im=0;
    for(long long int i=n1+1;i<n2;i++){
        gcd_im=gcd(i,m);
        if(m/gcd_im==k&&m%gcd_im==0){
            if(first) {cout<<i/gcd_im<<'/'<<k;first=0;}
            else cout<<' '<<i/gcd_im<<'/'<<k;
        }
    }
    return 0;
}
