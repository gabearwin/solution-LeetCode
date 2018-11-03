#include<iostream>
#include<cstring>
using namespace std;
const int maxn=10010;
char phone[maxn][11];
bool con(char s1[],int len1,char s2[],int len2){
    for(int j=0;j<=len2-len1;j++){
        if(s1[0]==s2[j]){
            int flag=1;
            for(int i=1;i<len1;i++){
                if(s1[i]!=s2[i+j]){
                    flag=0;break;
                }
            }
            if(flag==1) return true;
        }
    }
    return false;
}
int main(){
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>phone[i];
        }
        int flag=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int len1=strlen(phone[i]),len2=strlen(phone[j]);
                if(len1<=len2){
                    if(con(phone[i],len1,phone[j],len2)){
                        flag=0;
                        break;
                    }
                }
            }
            if(!flag) break;
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
