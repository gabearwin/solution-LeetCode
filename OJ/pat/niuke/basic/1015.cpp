#include<stdio.h>
#include<string.h>
int main(){
    char a[1000];
    while(scanf("%s",a)!=EOF){
        //printf("%c %d",a[2],strlen(a));
        int length=strlen(a),power=2,sum=0,ans=0;
        for(int i=length-1;i>=0;i--){
            sum=(a[i]-'0')*(power-1);
            power=power*2;
            ans+=sum;
        }
        printf("%d\n",ans);
    }
    return 0;
}
