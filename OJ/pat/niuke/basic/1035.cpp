#include<stdio.h>
#include<string.h>
void from_to(char s[],int from,int to){
    for(int i=from;i<=(to+from)/2;i++){
        char temp;
        temp=s[i];
        s[i]=s[to-i+from];
        s[to-i+from]=temp;
    }
}
int main(){
    char str[90];
    while(gets(str)){
        from_to(str,0,strlen(str)-1);
        //printf("%s\n",str);
        int length=strlen(str);
        char end_char=str[length];
        str[length]=' ';
        str[length+1]=end_char;
        int from=0,to=0;
        for(int i=0;i<=strlen(str);i++){
            if(str[i]==' '){
                to=i-1;
                from_to(str,from,to);
                from=i+1;
                to=i+1;
            }
        }
        str[length]=end_char;
        printf("%s\n",str);
    }
    return 0;
}
