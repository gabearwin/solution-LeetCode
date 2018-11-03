#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
void out(long long int a,long long int b){
    long long int temp_a=a;
    if(b<0) {b=-b;a=-a;temp_a=a;}
    //cout<<a<<' '<<b<<' ';
    long long int c=a/b;
    a=abs(a);
    long long int d=a%b;
    long long int e=gcd(d,b);
    if(c==0){
        if(d==0) cout<<0;
        else if(temp_a>0) printf("%d/%d",d/e,b/e);
        else if(temp_a<0) printf("(-%d/%d)",d/e,b/e);
    }else if(c>0){
        if(d==0) printf("%d",c);
        else printf("%d %d/%d",c,d/e,b/e);
    }else{
        if(d==0) printf("(%d)",c);
        else printf("(%d %d/%d)",c,d/e,b/e);
    }
}
int main(){
    long long int a1,b1,a2,b2;
    scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
    /*add*/
    out(a1,b1);cout<<" + ";out(a2,b2);cout<<" = ";out(a1*b2+a2*b1,b1*b2);cout<<endl;
    /*subtract*/
    out(a1,b1);cout<<" - ";out(a2,b2);cout<<" = ";out(a1*b2-a2*b1,b1*b2);cout<<endl;
    /*multiply*/
    out(a1,b1);cout<<" * ";out(a2,b2);cout<<" = ";out(a1*a2,b1*b2);cout<<endl;
    /*divide*/
    out(a1,b1);cout<<" / ";out(a2,b2);cout<<" = ";
    if(a2==0) cout<<"Inf";
    else out(a1*b2,b1*a2);
    return 0;
}
