#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<cstring>
#include<ctype.h>
#include<cmath>
using namespace std;

int main(){
    cout<<(int)sqrt(9999)<<endl;
    char cc=1+'J';
    cout<<cc<<endl;
    string s="abcdefg";
    cout<<s.length()<<endl;
    cout<<s.substr(2,1)<<endl;
    cout<<s.substr(2,3)<<endl;
    char b[]="1.234";
    double c=atof(b);
    cout<<c<<endl;
    int a=123;
    //cout<<a.length()<<endl;
    char d[10];
    sprintf(d,"%f",c);
    cout<<d<<endl<<strncmp(b,d,strlen(b))<<endl;
}
