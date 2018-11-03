#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=100000;
int a[maxn];
int cmp(const void *a, const void *b) { return *(int*)b - *(int*)a; }
int main(){
    int n,i=0;
    memset(a,0,sizeof(a));
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    //sort(a,a+n,cmp);
    qsort(a, n, sizeof(int), cmp);
    for(i=0;i<n&&a[i]>i+1;i++);
    cout<<i;
    return 0;
}
