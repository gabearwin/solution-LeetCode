#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=100000;
double a[maxn];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m=0,M=n-1,weight=n;
    double sum=0.0;
    for(int i=0;i<n/2;i++,m++,M--){
        sum+=1.0*(a[m]+a[M])*weight;
        weight+=n-2*(i+1);
    }
    if(n%2!=0){
        sum+=a[n/2]*weight;
    }
    printf("%.2f",sum);
    return 0;
}
