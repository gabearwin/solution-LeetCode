#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int n;
    cin>>n;
    double a,sum=0;
    for(int i=0;i<n;i++){
        cin>>a;
        sum+=a*(i+1)*(n-i);
    }
    printf("%.2lf",sum);
    return 0;
}
