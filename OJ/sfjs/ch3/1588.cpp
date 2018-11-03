#include<stdio.h>
#include<string.h>
#define maxn 100
char s1[maxn],s2[maxn];
int main(){
    memset(s1,' ',sizeof(s1));
    memset(s2,' ',sizeof(s2));
    while(scanf("%s%s",s1,s2)!=EOF){
        int len1=strlen(s1),len2=strlen(s2),flag=0,ans=0;
        for(int i=0;i<len1;i++){
            flag=0;
            if(s1[i]-'0'+s2[0]-'0'<=3){
                int len3=i+len2-len1,j,k=1;
                flag=1;
                if(len3>0){
                    for(int j=i;j<len1;j++,k++){
                        if(s1[j]-'0'+s2[k]-'0'>3) flag=0;
                    }
                    if(flag==1) ans=len1+len3;
                }else{
                    for(int j=1;j<len2;j++){
                        if(s1[i+j]-'0'+s2[j]-'0'>3) flag=0;
                    }
                    if(flag==1) ans=len1;
                }
            }
            if(flag==1) break;
        }
        if(flag==1) printf("%d\n",ans);
        else printf("%d\n",len1+len2);
        memset(s1,' ',sizeof(s1));
        memset(s2,' ',sizeof(s2));
    }
    return 0;
}
