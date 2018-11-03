#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int n,weight[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char m[]={'1','0','X','9','8','7','6','5','4','3','2'};
    char s[18];
    int flag=1,sum=0,i,z;
    cin>>n;
    while(n--){
        cin>>s;
        sum=0;
        for(i=0;i<17;i++){
            if(!isdigit(s[i])) break;
            sum+=(s[i]-'0')*weight[i];
        }
        if(i!=17) {flag=0;cout<<s<<endl;}
        else {
            z=sum%11;
            if(m[z]!=s[17]) {flag=0;cout<<s<<endl;}
        }
    }
    if(flag==1) cout<<"All passed";
    return 0;
}
