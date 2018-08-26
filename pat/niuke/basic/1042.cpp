#include<stdio.h>
int main(){
    int a[1000],b[1000],i=0;
    char c;
    while(scanf("%d %d%c",&a[i],&b[i],&c)!=EOF){
        i++;
        if(c!=' ') break;
    }
    if(b[0]==0){
        printf("0 0");
        return 0;
    }
    int first=1;
    for(int j=0;j<i;j++){
        a[j]=a[j]*b[j];
        b[j]=b[j]-1;
        if(a[j]!=0){
            if(first==1){
                printf("%d %d",a[j],b[j]);
                first=0;
            }else{
                printf(" %d %d",a[j],b[j]);
            }
        }
    }
    printf("\n");
    return 0;
}
