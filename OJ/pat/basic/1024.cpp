#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
const int maxn=10000;
char s[maxn];
int main(){
    memset(s,'\0',sizeof(s));
    cin>>s;
    int len=strlen(s);
    int index_e=0;
    for(int i=0;i<len;i++){
        if(s[i]=='E'){
            index_e=i;
            s[i]='\0';
            break;
        }
    }
    int a=atoi(s+index_e+1),i;
    //cout<<a<<endl;
    if(s[0]=='-') cout<<'-';
    if(a==0) cout<<s+1;
    else if(a>0){
        int len1=index_e-2-1;
        if(a>=len1){
            cout<<s[1]<<s+3;
            for(int i=0;i<a-len1;i++) cout<<0;
        }else{
            cout<<s[1];
            for(i=3;i-3<a;i++) cout<<s[i];
            cout<<'.'<<s+i;
        }
    }else if(a<0){
        a=-a;
        cout<<"0.";
        for(int i=0;i<a-1;i++) cout<<0;
        cout<<s[1]<<s+3;
    }
    return 0;
}
