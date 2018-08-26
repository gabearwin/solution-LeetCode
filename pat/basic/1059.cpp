#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int find_rank(int a[],int n,int num){
    for(int i=0;i<n;i++){
        if(a[i]==num) return ++i;
    }
    return 0;
}
bool isprime(int n){
    for(int i=2;i<sqrt(n)+1;i++){
        if(n%i==0) return false;
    }
    return true;
}
int main(){
    int n,a[10000],k,num,b[10000]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%d",&num);
        int rank_num=find_rank(a,n,num);
        if(rank_num==0){
            printf("%04d: Are you kidding?\n",num);
            continue;
        }
        if(b[rank_num-1]==1){
            printf("%04d: Checked\n",num);
        }else if(rank_num==1){
            printf("%04d: Mystery Award\n",num);
            b[rank_num-1]=1;
        }else if(isprime(rank_num)){
            printf("%04d: Minion\n",num);
            b[rank_num-1]=1;
        }else{
            printf("%04d: Chocolate\n",num);
            b[rank_num-1]=1;
        }
    }
    return 0;
}
