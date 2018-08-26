#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    char c;
    int P=0,A=0,T=0,e=0,s=0,t=0;
    while((c=getchar())!='\n'){
        if(c=='P') P++;
        else if(c=='A') A++;
        else if(c=='T') T++;
        else if(c=='e') e++;
        else if(c=='s') s++;
        else if(c=='t') t++;
    }
    while(P>0||A>0||T>0||e>0||s>0||t>0){
        if(P>0) {cout<<'P';P--;}
        if(A>0) {cout<<'A';A--;}
        if(T>0) {cout<<'T';T--;}
        if(e>0) {cout<<'e';e--;}
        if(s>0) {cout<<'s';s--;}
        if(t>0) {cout<<'t';t--;}
    }
    return 0;
}
