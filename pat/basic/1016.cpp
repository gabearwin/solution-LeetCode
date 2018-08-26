#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char a[12],b[12];
    int aa,bb,sum1=0,sum2=0;
    cin>>a>>aa>>b>>bb;
    for(int i=0;i<strlen(a);i++){
        if(a[i]-'0'==aa) sum1=sum1*10+aa;
    }
    for(int i=0;i<strlen(b);i++){
        if(b[i]-'0'==bb) sum2=sum2*10+bb;
    }
    cout<<sum1+sum2<<endl;
}
