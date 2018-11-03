#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
using namespace std;
char *mystrrev(char *str){
    int len=strlen(str);
    for(int i=0;i<len/2;i++){
        swap(str[i],str[len-1-i]);
    }
    return str;
}
int main(){
    char s1[100]="12345678";
    char s2[]="00200";
    cout<<strrev(s1)<<endl;
    cout<<mystrrev(s1)<<endl;
}

