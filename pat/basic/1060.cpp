#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=100000;
int a[maxn];
int cmp(int a,int b){
    if(a!=b) return a>b;
}
int main(){
    int n,i=0;
    memset(a,0,sizeof(a));
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    sort(a,a+n,cmp);
    for(i=0;i<n&&a[i]>i+1;i++);
    cout<<i;
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)b - *(int*)a; }
int main()
{
    int N, E, miles[100000];
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", miles + i);
    qsort(miles, N, sizeof(int), cmp);
    for(E = 0; E < N && miles[E] > E + 1; E++) ;
    printf("%d", E);
}
