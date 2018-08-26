#include<stdio.h>
#include<string.h>
bool less(char *s,int i,int ans){
    int len=strlen(s);
    for(int j=0;j<len;j++){
        //if(s[(i+j)%len]!=s[(ans+j)%len])
        //    return s[(i+j)%len]<s[(ans+j)%len];
        if(s[(i+j)%len]!=s[(ans+j)%len])
            return s[(i+j)%len]<s[(ans+j)%len]?true:false;
    }
    return false;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        char s[101];
        scanf("%s",s);
        int len=strlen(s),ans=0;
        for(int i=0;i<len;i++){
            if(less(s,i,ans)) ans=i;
        }
        for(int i=0;i<len;i++){
            putchar(s[(i+ans)%len]);
        }
        putchar('\n');
    }
    return 0;
}
