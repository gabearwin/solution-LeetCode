#include<stdio.h>
int main(){
    int n,sum=0,ans=0,a[1000];
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    ans=(sum*10+sum)*(n-1);
    printf("%d",ans);
    return 0;
}
