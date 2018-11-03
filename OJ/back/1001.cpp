#include<stdio.h>
int main(){
    int n,m;
    while(scanf("%d",&m)!=EOF&&m!=0){
        scanf("%d",&n);
        int a[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        int tmp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&tmp);
                a[i][j]+=tmp;
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            int flag=0;
            for(int j=0;j<n;j++){
                if(a[i][j]!=0) {flag=1;break;}
            }
            if(flag==0) ans++;
        }
        for(int i=0;i<n;i++){
            int flag=0;
            for(int j=0;j<m;j++){
                if(a[j][i]!=0) {flag=1;break;}
            }
            if(flag==0) ans++;
        }
        printf("%d\n",ans);
    }
}
