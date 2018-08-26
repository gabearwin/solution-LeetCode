#include<stdio.h>
#include<string.h>
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        char s[81];
        scanf("%s",s);
        int len=strlen(s);
        int last=1,score=0;
        for(int i=0;i<strlen(s);i++){
            if(s[i]=='O'){
                if(last==1) {score+=1;last++;}
                else {score+=last;last++;}
            }else{
                last=1;
            }
        }
        printf("%d\n",score);
    }
    return 0;
}
