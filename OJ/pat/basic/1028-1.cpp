#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char s[17],a[17],b[17];
    memset(s,'\0',sizeof(s));
    memset(a,'\0',sizeof(a));
    memset(b,'\0',sizeof(b));
    strcpy(a+6,"9999/12/31");
    int n,cnt=0;
    cin>>n;
    while(n--){
        cin>>s>>s+6;
        if(strcmp(s+6,"1814/09/06")>=0&&strcmp(s+6,"2014/09/06")<=0){
            if(strcmp(s+6,a+6)<0) {strcpy(a,s);strcpy(a+6,s+6);}
            if(strcmp(s+6,b+6)>0) {strcpy(b,s);strcpy(b+6,s+6);}
            cnt++;
            //cout<<a<<endl<<a+6<<endl;
            //cout<<b<<endl<<b+6<<endl;
        }
    }
    if(cnt==0) cout<<0;
    else cout<<cnt<<' '<<a<<' '<<b;
    return 0;
}
