#include<stdio.h>
int main(){
    int m,n,a,b,c,arr[501][501];
    while(scanf("%d%d%d%d%d",&m,&n,&a,&b,&c)!=EOF){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&arr[i][j]);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]>=a&&arr[i][j]<=b) arr[i][j]=c;
                if(j!=n-1) printf("%03d ",arr[i][j]);
                else printf("%03d\n",arr[i][j]);
            }
        }
    }
    return 0;
}
