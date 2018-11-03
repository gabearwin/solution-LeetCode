#include<stdio.h>
int main(){
    int a;
    while(scanf("%d",&a)!=EOF){
        int f1=7,f2=11,f3=0;
        if(a==0) f3=7;
        if(a==1) f3=11;
        if(a>1){
            for(int i=0;i<a-1;i++){
                f3=f2+f1;
                f1=f2;
                f2=f3;
            }
        }
        if(f3%3==0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

#include<stdio.h>
int main(){
    int n;
    while(scanf("%d", &n)!=EOF) {
        if(input % 4 == 2){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}
