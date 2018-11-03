#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int m,n,tol;
    scanf("%d%d%d",&n,&m,&tol);
    long long int a[1001][1001];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    int cnt=0;
    int x=0,y=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(abs(a[i][j]-a[i-1][j-1])>tol&&abs(a[i][j]-a[i-1][j])>tol&&abs(a[i][j]-a[i-1][j+1])>tol&&abs(a[i][j]-a[i][j-1])>tol&&abs(a[i][j]-a[i][j+1])>tol&&abs(a[i][j]-a[i+1][j-1])>tol&&abs(a[i][j]-a[i+1][j])>tol&&abs(a[i][j]-a[i+1][j+1])>tol)
                {
                    int flag=1;
                    for(int ii=0;ii<m;ii++){
                        for(int jj=0;jj<n;jj++){
                            if(a[ii][jj]==a[i][j]&&ii!=i&&jj!=j) flag=0;
                        }
                    }
                    if(flag==1){cnt++;x=i;y=j;}
                }
                //{cnt++;printf("(%d, %d): %lld\n",i,j,a[i][j]);}
            if(cnt>1){printf("Not Unique\n");return 0;}
        }
    }
    if(cnt==1){
        printf("(%d, %d): %lld\n",y+1,x+1,a[x][y]);
        return 0;
    }
    if(cnt==0){
        printf("Not Exist\n");
        return 0;
    }
}
