#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int c=floor((b-a)*1.0/100+0.5);
    int h=c/3600;
    int m=c%3600/60;
    int s=c%3600%60;
    printf("%02d:%02d:%02d\n",h,m,s);
}
