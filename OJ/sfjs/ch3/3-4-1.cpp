#include<stdio.h>
#include<string.h>
int main(){
    int count=0;
    char num[]="123456789",s[20];
    for(int x=1000;x<=9999;x++){
        for(int y=1;y<=9;y++){
            int z=x*y,ok=0;
            sprintf(s,"%d%d%d",x,y,z);
            for(int i=0;i<strlen(num);i++)
                if(strchr(s,num[i])) ok++;
            if(ok==9&&z<=9999) printf("%d %d %d\n",x,y,z);
        }
    }
    return 0;
}
