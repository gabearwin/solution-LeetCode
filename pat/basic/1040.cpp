#include<iostream>
#include<cstring>
using namespace std;
const int maxn=100001;
char s[maxn];
int main(){
    cin>>s;
    int len=strlen(s);
    int P=0,PA=0,PAT=0,M=1000000007;
    for(int i=0;i<len;i++){
        if(s[i]=='P') P++;
        if(s[i]=='A') PA=(PA+P)%M;
        if(s[i]=='T') PAT=(PAT+PA)%M;
    }
    cout<<PAT;
    return 0;
}
