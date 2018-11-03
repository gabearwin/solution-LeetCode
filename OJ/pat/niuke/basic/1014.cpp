#include<stdio.h>
#include<math.h>
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int last=1,cnt=0;
        for(int i=2;i<=(int)sqrt(n)+1;i++ ){
            if(n%i==0){
                if(i!=last){
                    //printf("%d ",i);
                    last=i;
                    cnt++;
                }
                n=n/i;
                i=1;
            }
        }
        if(n!=last&&n!=1) cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
