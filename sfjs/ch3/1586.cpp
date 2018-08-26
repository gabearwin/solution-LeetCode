#include<stdio.h>
#include<string.h>
#include<ctype.h>
double mass(char c){
    if(c=='C') return 12.01;
    if(c=='H') return 1.008;
    if(c=='O') return 16.00;
    if(c=='N') return 14.01;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        char s[81];
        scanf("%s",s);
        int len=strlen(s);
        double molar=0.0;
        int i=1;
        while(i<len&&s[i]!='\0'){
            if(isdigit(s[i])){
                if(isdigit(s[i+1])){
                    int num=10*(s[i]-'0')+s[i+1]-'0';
                    molar+=num*mass(s[i-1]);
                    i+=3;
                }else{
                    molar+=(s[i]-'0')*mass(s[i-1]);
                    i+=2;
                }
            }else{
                molar+=mass(s[i-1]);
                i++;
            }
        }
        if(i==len) molar+=mass(s[i-1]);
        printf("%.3f\n",molar);
    }
    return 0;
}
