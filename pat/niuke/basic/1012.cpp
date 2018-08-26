#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
int gcd(int a,int b){
    return b!=0?gcd(b,a%b):a;
}
int main(){
    int a,b,c,d;
    char e;
    while(scanf("%d/%d %d/%d %c",&a,&b,&c,&d,&e)!=EOF){
        //printf("%d %d %d %d",a,b,c,d);
        if(e=='+'){
            int temp=gcd(a*d+b*c,d*b);
            printf("%d/%d\n",(a*d+b*c)/temp,(d*b)/temp);
        }
        if(e=='-'){
            int temp=gcd(abs(a*d-b*c),d*b);
            if(a*d-b*c==0) printf("0\n");
            else printf("%d/%d\n",(a*d-b*c)/temp,(d*b)/temp);
        }
        if(e=='*'){
            int temp=gcd(a*c,d*b);
            printf("%d/%d\n",(a*c)/temp,(d*b)/temp);
        }
        if(e=='/'){
            int temp=gcd(a*d,c*b);
            printf("%d/%d\n",(a*d)/temp,(c*b)/temp);
        }
    }
    return 0;
}
