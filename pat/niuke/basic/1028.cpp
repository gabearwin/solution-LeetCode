#include<stdio.h>
#include<string.h>
int main(){
    char a[10001],b[10001];
    while(scanf("%s%s",a,b)!=EOF){
        int c[26]={0},d[26]={0};
        for(int i=0;i<strlen(a);i++){
            c[a[i]-'A']++;
        }
        for(int i=0;i<strlen(b);i++){
            d[b[i]-'A']++;
        }
        int flag=1;
        for(int i=0;i<26;i++){
            if(d[i]>c[i]){
                flag=0;
                break;
            }
        }
        if(flag==1){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}
