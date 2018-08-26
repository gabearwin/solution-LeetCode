#include<stdio.h>
#include<string.h>
int main(){
    char str[81];
    while(gets(str)){
        char ans[81][81];
        int cnt1=0,cnt2=0,len=strlen(str);
        for(int i=0;i<len;i++){
            if(str[i]!=' '){
                ans[cnt1][cnt2++]=str[i];
            }else{
                cnt1++;
                cnt2=0;
            }
        }
        for(int i=cnt1;i>=0;i--){
            printf("%s",ans[i]);
            if(i!=0) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
