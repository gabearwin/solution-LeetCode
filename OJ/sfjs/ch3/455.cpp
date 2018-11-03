#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        char s[100];
        scanf("%s",s);
        int len=strlen(s),ans=0;
        char str[100];
        for(int i=0;i<len/2;i++){
            char temp[100];
            memset(temp,'\0',sizeof(temp));
            memset(str,'\0',sizeof(str));
            strncpy(temp,s,i+1);
            //printf("%s\n",temp);
            if(len%(i+1)==0){
                for(int j=1;j<=len/(i+1);j++){
                    strcat(str,temp);
                }
                //printf("%s\n",str);
                if(strcmp(str,s)==0) {ans=i+1;break;}
            }
        }
        //提交了好几次，一直有问题，主要在下面两点
        printf("%d\n",ans==0?len:ans);//如果ans=0的时候要让ans=len，就是全部长度循环一次
        if(T!=0) printf("\n");//输出格式错误，最后一个测试用例输出之后不要空行
    }
    return 0;
}
