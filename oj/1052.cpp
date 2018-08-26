#include<stdio.h>
int main(){
    int n,answer,i,x;
    while(scanf("%d",&n)!=EOF){
        answer=-1;
        int buf[201]={0};
        for(i=0;i<n;i++){
            scanf("%d",&buf[i]);
        }
        scanf("%d",&x);
        for(i=0;i<n;i++){
            if(buf[i]==x){
                answer=i;
                break;
            }
        }
        printf("%d\n",answer);
    }
    return 0;
}
