#include<stdio.h>
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        while(n--){
            int k,i,buf[100],flag=0;
            scanf("%d",&k);
            for(i=0;i<k;i++){
                scanf("%d",&buf[i]);
            }
            if(buf[0]!=buf[1]) {printf("%d",0); flag=1;}
            for(i=1;i<k-1;i++){
                if((buf[i]<buf[i-1]&&buf[i]<buf[i+1])||(buf[i]>buf[i-1]&&buf[i]>buf[i+1])){
                    if(flag==1) printf(" %d",i);
                    else {printf("%d",i); flag=1;}
                }
            }
            if(buf[k-1]!=buf[k-2]) printf(" %d\n",k-1);
            else printf("\n");
        }
    }
    return 0;
}
