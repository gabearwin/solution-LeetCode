#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int szh(int n){
    int sum=0;
    for(int i=0;i<5;i++){
        sum+=n%10;
        n=n/10;
    }
    return sum;
}
int main(){
    int n,a[10000],b[10000],j=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[j++]=szh(a[i]);
    }
    sort(b,b+j);
    int c[10000],k=0;
    c[0]=b[0];
    for(int i=1;i<j;i++){
        if(b[i]!=c[k]){
            c[++k]=b[i];
        }
    }
    k++;
    printf("%d\n",k);
    int first=1;
    for(int i=0;i<k;i++){
        if(first==1) {first=0;printf("%d",c[i]);}
        else printf(" %d",c[i]);
    }
    printf("\n");
    return 0;
}
