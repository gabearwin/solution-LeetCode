#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    char c;
    int a[128]={0},len1=0,len2=0,flag=1,cnt=0;
    while((c=getchar())!='\n'){
        len1++;
        a[c]++;
    }
    while((c=getchar())!='\n'){
        len2++;
        a[c]--;
        if(a[c]<0){
            flag=0;
            cnt++;
        }
    }
    if(flag==1){
        cout<<"Yes"<<' '<<len1-len2;
    }else{
        cout<<"No"<<' '<<cnt;
    }
}
