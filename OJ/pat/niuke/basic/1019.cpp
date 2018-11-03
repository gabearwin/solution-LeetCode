#include<stdio.h>
bool hw(int n,int r){
    int a[1000],i=0;
    while(n!=0){
        a[i++]=n%r;
        n=n/r;
    }
    for(int j=0;j<i;j++){
        if(a[j]!=a[i-1-j]){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int flag=0;
        for(int i=2;i<=16;i++){
            if(hw(n,i)==true){flag=1;break; }
        }
        if(flag==1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
