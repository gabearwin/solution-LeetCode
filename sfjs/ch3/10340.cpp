#include<stdio.h>
#include<string.h>
#define maxn 100000
char s[maxn],t[maxn];
int main(){
    memset(s,' ',sizeof(s));
    memset(t,' ',sizeof(t));
    while(scanf("%s%s",s,t)!=EOF){
        int len1=strlen(s),len2=strlen(t);
        int i=0,j=0,count=0;
        for(i=0;i<len1;i++){
            while(j<len2){
                if(s[i]==t[j++]) {count++;break;}
            }
        }
        if(count==len1) printf("Yes\n");
        else printf("No\n");
    }
}
