#include<stdio.h>
bool ss(int a){
    for(int i=2;i<a/2;i++){
        if(a%i==0) return false;
    }
    return true;
}
int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        if(a==0&&b==0) break;
        int flag=1;
        for(int i=a;i<=b;i++){
            if(ss(i*i+i+41)==false){
                flag=0;
                break;
            }
        }
        if(flag==1){
            printf("OK\n");
        }else{
            printf("Sorry\n");
        }
    }
    return 0;
}
