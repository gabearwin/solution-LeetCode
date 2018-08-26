#include<iostream>
using namespace std;
int main(){
    char s[81][81];
    int cnt=0;
    while(cin>>s[cnt]){cnt++;}
    for(int i=cnt-1;i>=0;i--){
        if(i==cnt-1) cout<<s[i];
        else cout<<' '<<s[i];
    }
    cout<<endl;
    return 0;
}
