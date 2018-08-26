#include<stdio.h>
#include<string.h>
int main(){
    char s[100];
    while(scanf("%s",s)!=EOF){
        int a[10]={0};
        for(int i=0;i<strlen(s);i++){
            a[s[i]-'0']++;
        }
        int maxnum=0;
        for(int i=0;i<10;i++){
            if(a[i]>maxnum) maxnum=a[i];
        }
        for(int i=maxnum;i>0;i--){
            for(int j=0;j<10;j++){
                if(a[j]==i){
                    printf("*");
                    a[j]--;
                }
                else printf(" ");
            }
            printf("\n");
        }
        printf("0123456789\n");
    }
    return 0;
}
