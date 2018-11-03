#include<stdio.h>
long long honi(int x){
    if(x==1) return 2;
    else return 3*honi(x-1)+2;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%lld\n",honi(n));
    }
    return 0;
}
