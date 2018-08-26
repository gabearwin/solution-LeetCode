#include<stdio.h>
#include<math.h>
bool sushu(int x){
    if(x<=1) return false;
    for(int i=2;i<sqrt(x)+1;i++){
        if(x%i==0) return false;
    }
    return true;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%s\n",sushu(n)?"yes":"no");
    }
}
