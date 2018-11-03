#include<stdio.h>
int main(){
    int i;
    for(i=1000;i<=9999;i++){
        int a1=i%10,a2=(i/10)%10,a3=(i/10/10)%10,a4=(i/10/10/10);
        int j=i*9;
        int b1=j%10,b2=(j/10)%10,b3=(j/10/10)%10,b4=(j/10/10/10);
        if(a1==b4&&a2==b3&&a3==b2&&a4==b1) printf("%d\n",i);
    }
    return 0;
}
