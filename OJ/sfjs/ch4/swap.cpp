#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=10000;
int flag=0,first,last;
char line[maxn];
void out(char line[],int first,int last){
    if(flag++) printf(" ");
    for(int i=first;i<=last;i++) printf("%c",line[i]);
}
int main(){
    while(cin.getline(line,maxn)){
        flag=0,first=last=strlen(line)-1;
        while(first>0){
            if(line[first]==' '){
                out(line,first+1,last);
                first=last=first-1;
            }else{
                first--;
            }
        }
        out(line,first,last);
        printf("\n");
    }
}
