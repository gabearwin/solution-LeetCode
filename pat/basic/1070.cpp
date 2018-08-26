#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int a[10000];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int ans=a[0];
    for(int i=1;i<n;i++){
        ans=(ans+a[i])/2;
    }
    printf("%d",ans);
    return 0;
}
