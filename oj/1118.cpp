#include<stdio.h>
#include<string.h>
int main(){
    int a,b;
    char str[100];
    while(scanf("%d%s%d",&a,str,&b)!=EOF){
        int x,tmp=0,m=1,j=0;
        for(int i=strlen(str)-1;i>=0;i--){
            if(str[i]>='0'&&str[i]<='9') x=str[i]-'0';
            else if(str[i]>='a'&&str[i]<='z') x=str[i]-'a'+10;
            else if(str[i]>='A'&&str[i]<='Z') x=str[i]-'A'+10;
            tmp+=x*m;
            m=m*a;
        }
        char ans[100];
        do{
            ans[j++]=(tmp%b>=10)?tmp%b-10+'A':tmp%b+'0';
            tmp=tmp/b;
        }while(tmp);
        for(int k=j-1;k>=0;k--) printf("%c",ans[k]);
        printf("\n");
    }
    return 0;
}
