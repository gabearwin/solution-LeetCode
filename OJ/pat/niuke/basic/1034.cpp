#include<stdio.h>
void next(int a[],int n){
    int temp=a[n-1];
    for(int i=n-1;i>0;i--) a[i]=a[i-1];
    a[0]=temp;
}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int a[100];
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=m;i++) next(a,n);
        int first=0;
        for(int i=0;i<n;i++){
            if(first==0) {printf("%d",a[i]);first=1;}
            else printf(" %d",a[i]);
        }
        printf("\n");
    }
    return 0;
}
