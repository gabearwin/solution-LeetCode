#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    long long int a,b,c;
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>a>>b>>c;
        printf("Case #%d: ",i);
        printf("%s\n",(a-c+b)>0?"true":"false");
    }
    return 0;
}
