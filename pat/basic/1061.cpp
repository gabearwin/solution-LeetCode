#include<stdio.h>
int main(){
    int n,m,score[100],ans[100],stu[100][100],sum;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) scanf("%d",&score[i]);
    for(int i=0;i<m;i++) scanf("%d",&ans[i]);
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=0;j<m;j++){
            scanf("%d",&stu[i][j]);
            if(stu[i][j]==ans[j]){
                sum+=score[j];
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
