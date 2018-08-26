#include<stdio.h>
#include<string.h>
bool cmp(char s1[],char s2[]){
    int len1=strlen(s1),len2=strlen(s2);
    if(len1!=len2) return false;
    for(int i=0;i<len1;i++){
        if(s1[i]!=s2[i]) return false;
    }
    return true;
}
int main(){
    int m,n,s;
    char name[1000][100];
    scanf("%d%d%d",&m,&n,&s);
    for(int i=0;i<m;i++){
        scanf("%s",name[i]);
    }
    if(s>m){
        printf("Keep going...");
    }else{
        int prizenum=0,prize[1000];
        while(s<=m){
            int flag=0;
            for(int i=0;i<prizenum;i++){
                int temp=prize[i];
                if(cmp(name[s-1],name[temp])){
                    s++;
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                prize[prizenum++]=s-1;
                printf("%s\n",name[s-1]);
                s=s+n;
            }
        }
    }
    return 0;
}
