#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    char s[10000];
    while(scanf("%s",s)!=EOF){
        int sum=0,i=0,j=0,a[1000];
        while(s[i]!='\0'){
            sum+=s[i]-'0';
            i++;
        }
        if(sum==0){
            printf("ling\n");
            continue;
        }
        while(sum!=0){
            a[j++]=sum%10;
            sum=sum/10;
        }
        for(j=j-1;j>=0;j--){
            switch(a[j]){
                case 0:printf("ling"); break;
                case 1:printf("yi"); break;
                case 2:printf("er"); break;
                case 3:printf("san"); break;
                case 4:printf("si"); break;
                case 5:printf("wu"); break;
                case 6:printf("liu"); break;
                case 7:printf("qi"); break;
                case 8:printf("ba"); break;
                case 9:printf("jiu"); break;
            }
            if(j==0){break;}
            else{printf(" ");}
        }
        printf("\n");
    }
    return 0;
}
