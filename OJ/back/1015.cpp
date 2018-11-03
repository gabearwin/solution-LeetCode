#include<stdio.h>
#include<math.h>
int main(){
    int a,b,k;
    while(scanf("%d%d%d",&a,&b,&k)!=EOF){
        if(a==0&&b==0) break;
        int c=1;
        for(int i=0;i<k;i++) c=c*10;
        if(a%c==b%c) printf("-1\n");
        else printf("%d\n",a+b);
    }
    return 0;
}
