#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
    char s[100];
    gets(s+1);
    s[0]=' ';
    for(int i=strlen(s)-1;i>=0;i--){
        if(s[i]==' ') {cout<<s+i+1;s[i]='\0';}
        else continue;
        if(i==0) cout<<endl;
        else cout<<' ';
    }
    return 0;
}
