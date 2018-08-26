#include<stdio.h>
#include<string.h>
bool cmp_pass(char pass[],char trypass[]){
    int len1=strlen(pass),len2=strlen(trypass);
    if(len1!=len2) return false;
    for(int i=0;i<len1;i++){
        if(pass[i]!=trypass[i])
            return false;
    }
    return true;
}
int main(){
    char pass[21];
    int n,i=0;
    scanf("%s%d",pass,&n);
    if(n<1) n=1;
    if(n>10) n=10;
    getchar();
    for(i=0;i<n;i++){
        char trypass[21];
        //scanf("%s",trypass);
        gets(trypass);
        if(strlen(trypass)==0){i=i-1;continue;}
        if(strlen(trypass)==1&&trypass[0]=='#') return 0;
        if(cmp_pass(pass,trypass)){
            printf("Welcome in\n");
            return 0;
        }else{
            printf("Wrong password: %s\n",trypass);
        }
    }
    printf("Account locked\n");
    return 0;
}
