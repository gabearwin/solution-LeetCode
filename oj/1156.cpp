#include<stdio.h>
int main(){
    int n,m,i;
    while(scanf("%d%d",&n,&m)!=EOF){
        int hash[201]={0};
        int a[201]={0};
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            hash[a[i]]++;
        }
        for(i=1;i<=n;i++){
            if(hash[a[i]]>1){printf("%d\n",hash[a[i]]-1);}
            else printf("BeiJu\n");
        }
    }
    return 0;
}
