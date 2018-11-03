#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int n,a[1000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
    sort(a,a+n);//ÅÅÐò
    //for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
    n=unique(a,a+n)-a;//È¥ÖØÅÅÐò
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
    return 0;
}
