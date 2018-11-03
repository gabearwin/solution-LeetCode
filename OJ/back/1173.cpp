#include<stdio.h>
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int i,m,a[100]={0},b[100]={0};
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        scanf("%d",&m);
        for(i=0;i<m;i++){
            scanf("%d",&b[i]);
        }
        for(i=0;i<m;i++){
            int j=0;
            for(j=0;j<n;j++){
                if(b[i]==a[j]){
                    printf("YES\n");
                    break;
                }
            }
            if(j==n) printf("NO\n");
        }
    }
}
