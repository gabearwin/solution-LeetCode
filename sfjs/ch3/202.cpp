#include<stdio.h>
#include<string.h>
#define maxn 3000
int sh[maxn],yu[maxn];//分别保存商和保存余数
int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        int s_start=0,s_end=0;
        memset(sh,0,sizeof(sh));
        memset(yu,0,sizeof(yu));
        printf("%d/%d = %d.",a,b,a/b);
        yu[0]=a%b;
        for(int i=0;i<3000;i++){
            sh[i]=yu[i]*10/b;
            yu[i+1]=yu[i]*10%b;
            for(int j=0;j<i+1;j++){
                if(yu[j]==yu[i+1]){s_start=j;s_end=i+1;goto gg; }
            }
        }
    gg: for(int i=0;i<s_start;i++) printf("%d",sh[i]);
        printf("(");
        if(s_end-s_start<=50){
            for(int i=s_start;i<s_end;i++)
                printf("%d",sh[i]);
        }else{
            for(int i=s_start;i<s_start+50;i++)
                printf("%d",sh[i]);
            printf("...");
        }
        printf(")\n   %d = number of digits in repeating cycle\n\n",s_end-s_start);
    }
    return 0;
}
