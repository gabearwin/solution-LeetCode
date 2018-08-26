#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int cmp1(int a,int b){
    if(a!=b) return a>b;
}
int cmp2(int a,int b){
    if(a!=b) return a<b;
}
int main(){
    int n,s[5],a=0,b=0;
    cin>>n;
    if(n%1111==0) {printf("%d - %d = 0000\n",n,n);return 0;}
    do{
        s[3]=n/1000;
        s[2]=n/100%10;
        s[1]=n%100/10;
        s[0]=n%10;
        sort(s,s+4,cmp1);
        a=s[0]*1000+s[1]*100+s[2]*10+s[3];
        sort(s,s+4,cmp2);
        b=s[0]*1000+s[1]*100+s[2]*10+s[3];
        printf("%04d - %04d = %04d\n",a,b,a-b);
        n=a-b;
    }while(n!=6174);
    return 0;
}
