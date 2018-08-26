#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char s[1000];
    int a[10]={0};
    cin>>s;
    for(int i=0;i<strlen(s);i++){
        a[s[i]-'0']++;
    }
    for(int i=0;i<10;i++){
        if(a[i]!=0){
            cout<<i<<':'<<a[i]<<endl;
        }
    }
    return 0;
}
