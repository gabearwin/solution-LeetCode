#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
    int a;
    char c;
    cin>>a>>c;
    int b=(int)sqrt((a+1)/2);
    for(int i=0;i<b;i++){
        int d=(b-i)*2-1;
        for(int j=0;j<i;j++) cout<<' ';
        for(int j=0;j<d;j++) cout<<c;
        cout<<endl;
    }
    for(int i=b-2;i>=0;i--){
        int d=(b-i)*2-1;
        for(int j=0;j<i;j++) cout<<' ';
        for(int j=0;j<d;j++) cout<<c;
        cout<<endl;
    }
    cout<<a+1-2*b*b;
    return 0;
}
