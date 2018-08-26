#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int other(int a[][2],int b,int n){
    for(int i=0;i<n;i++){
        if(a[i][0]==b) return a[i][1];
        else if(a[i][1]==b) return a[i][0];
    }
    return 0;
}
bool in(int a[],int b,int m){
    for(int i=0;i<m;i++){
        if(a[i]==b) {a[i]=-1; return true;}
    }
    return false;
}
int main(){
    int n,m;
    scanf("%d",&n);
    int a[50000][2],b[10000];
    for(int i=0;i<n;i++){
        int j=0;
        scanf("%d",&a[i][j]);
        j++;
        scanf("%d",&a[i][j]);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++) scanf("%d",&b[i]);
    int k=m;
    for(int i=0;i<m;i++){
        if(b[i]==-1) continue;
        int rt1=other(a,b[i],n);
        //printf("%d\n",rt1);
        if(rt1!=0){
            if(in(b,rt1,m)){
                b[i]=-1;
                k-=2;
            }
        }
    }
    sort(b,b+m);
    printf("%d\n",k);
    int first=1;
    for(int i=m-k;i<m;i++){
        if(first==1){first=0;printf("%05d",b[i]); }
        else printf(" %05d",b[i]);
    }
    return 0;
}
