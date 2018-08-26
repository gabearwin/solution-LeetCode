#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char a[1000];
    int b,chu=0,shang[1000],cnt=0;
    cin>>a>>b;
    for(int i=0;i<strlen(a);i++){
        chu=chu*10+a[i]-'0';
        if(chu<b){
            shang[cnt++]=0;
        }else{
            shang[cnt++]=chu/b;
            chu=chu%b;
        }
    }
    int first=1;
    for(int i=0;i<cnt;i++){
        if(first==1){
            if(shang[i]!=0){
                cout<<shang[i];
                first=0;
            }
        }else{
            cout<<shang[i];
        }
    }
    if(first==1) cout<<0; //要注意此处。如1/2=0...1
    cout<<' '<<chu<<endl;
    return 0;
}
