#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main(){
    int n;
    char c[201];
    while(scanf("%s",&c)!=EOF){
        sort(c,c+strlen(c));
        printf("%s\n",c);
    }
}
