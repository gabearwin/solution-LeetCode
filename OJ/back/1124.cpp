#include<stdio.h>
#include<string.h>
int main(){
    char a[100];
    while(scanf("%s",a)!=EOF){
        if(strcmp(a,"0")==0) break;
        int ans=10;
        while(ans>=10){
            ans=0;
            for(int i=0;i<strlen(a);i++) ans+=a[i]-'0';
            sprintf(a,"%d",ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}
