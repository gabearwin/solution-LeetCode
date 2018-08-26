#include<stdio.h>
void result(int n,int &result_add,int &result_mul){
    int i=n/100,j=n%100/10,k=n%10;
    result_add+=i+j+k;
    result_mul*=i*j*k;
}
int main(){
    for(int i=123;i<=329;i++){
        int j=i*2,k=i*3;
        int result_add=0,result_mul=1;
        result(i,result_add,result_mul);
        result(j,result_add,result_mul);
        result(k,result_add,result_mul);
        if(result_add==45&&result_mul==362880)
            printf("%d %d %d\n",i,j,k);
    }
    return 0;
}
