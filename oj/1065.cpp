#include<stdio.h>
int main(){
    int h,i,j,maxline;
    while(scanf("%d",&h)!=EOF){
    maxline=h+(h-1)*2;
    for(i=1;i<=h;i++){
        for(j=1;j<=maxline;j++){
            if(j<=(h-i)*2) printf(" ");
            else printf("*");
        }
        printf("\n");
    }
    }
    return 0;
}
