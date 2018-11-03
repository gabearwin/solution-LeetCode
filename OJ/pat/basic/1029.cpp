#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    char a[100],b[100],c[100],e;
    cin>>a>>b;
    int len1=strlen(a),len2=strlen(b),ecnt=0;
    for(int i=0,j=0;i<len1;i++){
        if(a[i]!=b[j]){
            e=toupper(a[i]);
            int flag=0;
            for(int k=0;k<ecnt;k++){
                if(c[k]==e) {flag=1;break;}
            }
            if(flag==0){
                c[ecnt++]=e;
            }
        }else j++;
    }
    for(int i=0;i<ecnt;i++) cout<<c[i];
    return 0;
}
