#include<cstdio>
#include<cstring>
#include<stdlib.h>
#define maxn 10000
int main(){
    FILE *f1,*f2,*f3;
    f1=fopen("G://a.txt","r");
    f2=fopen("G://b.txt","r");
    f3=fopen("G://c.txt","w");
    if(!f1||!f2||!f3){
        printf("file open error\n");
        exit(0);
    }
    char str1[maxn],str2[maxn];
    while(fgets(str1,maxn,f1)&&fgets(str2,maxn,f2)){
        fputs(str1,f3);
        fputs(str2,f3);
    }
    memset(str1,' ',sizeof(str1));
    memset(str2,' ',sizeof(str2));
    while(fgets(str1,maxn,f1)||fgets(str2,maxn,f2)){
        fputs(str1,f3);
        fputs(str2,f3);
    }
    printf("OK\n");
    fclose(f1);
    fclose(f2);
    fclose(f3);
    return 0;
}
