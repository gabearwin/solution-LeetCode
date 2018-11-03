#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char s1[120],s2[120];
int len1,len2,ans;

void cmp(char s1[],char s2[]){
    len1=strlen(s1),len2=strlen(s2);
    for(int i=0;i<len1;i++){
        int flag=1;
        for(int j=0;j<len2&&i+j<len1;j++){
            if(s1[i+j]+s2[j]>='2'+'2'){flag=0;break; }
        }
        if(flag) ans=min(ans,max(len1,i+len2));
    }
}

int main(){
    while(~scanf("%s%s",s1,s2)){
        ans=strlen(s1)+strlen(s2);
        cmp(s1,s2);
        cmp(s2,s1);
        printf("%d\n",ans);
    }
    return 0;
}
