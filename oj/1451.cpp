/*a b c d
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

a b
1 2
2 1

a b c d
1
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 1 3
2 4 3 1

b[2]=1 a[3]=(3-1)*b[2]
a[4]=(4-1)*b[3] b[3]=a[2]+(3-1)*b[2]*/
#include<stdio.h>
int main(){
    int n;
    long long a[30],b[30];
    b[2]=1,a[2]=1,a[3]=2;
    for(int i=2;i<=18;i++){
        b[i+1]=a[i]+i*b[i];
        a[i+2]=(i+1)*b[i+1];
    }
    while(scanf("%d",&n)!=EOF){
        printf("%lld\n",a[n]);
    }
    return 0;
}

