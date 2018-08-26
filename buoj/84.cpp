#include<stdio.h>
int main(){
    int
    while(scanf("%d",&n)!=EOF){
        int a[n],b[n];
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
            b[i]=0;
        }
        int con=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<con;j++){
                if(b[j]==a[i]) break;
            }
            b[con++]=a[i];
        }
    }
}
