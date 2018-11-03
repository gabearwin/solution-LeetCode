#include<stdio.h>
int main(){
    int a;
    for(a=0;a<256;a++){
        int b=a*a,i=0,j,flag=1,c[1000];
        while(b){
            c[i++]=b%10;
            b=b/10;
        }
        for(j=0;j<i/2;j++){
            if(c[j]!=c[i-j-1]){
                flag=0;
                break;
            }
        }
        if(flag==1) printf("%d\n",a);
    }
    return 0;
}

//10  0-9   0 1 2 3 4 5 6 7 8 9
