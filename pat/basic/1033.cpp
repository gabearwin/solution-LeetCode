#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    char a;
    int s[128]={0}; //注意初始化，不然有问题
    while((a=getchar())!='\n'){
        s[a]=1;
    }
    while((a=getchar())!='\n'){
        if(s[a]!=1&&s[toupper(a)]!=1){
            if(s['+']==1&&isupper(a)) continue;
            cout<<a;
        }
    }
    cout<<endl;
    return 0;
}
