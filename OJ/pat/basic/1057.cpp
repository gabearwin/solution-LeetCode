#include<stdio.h>
#include<string.h>
int main(){
    char s[1000];
    gets(s);
    int cnt=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]>='a'&&s[i]<='z'){
            cnt+=s[i]-'a'+1;
        }else if(s[i]>='A'&&s[i]<='Z'){
            cnt+=s[i]-'A'+1;
        }
    }
    //printf("%d\n",cnt);
    int cnt0=0,cnt1=0;
    while(cnt!=0){
        if(cnt%2==0) cnt0++;
        if(cnt%2==1) cnt1++;
        cnt=cnt/2;
    }
    printf("%d %d\n",cnt0,cnt1);
    return 0;
}

//PAT (Basic)
