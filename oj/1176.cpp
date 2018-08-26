#include<stdio.h>
#include<math.h>
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int a[1000]={0};
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);

        }
        int ceng=1,d;
        while((pow(2,ceng)-1)<n) ceng++;
        scanf("%d",&d);
        if(d>ceng) printf("EMPTY\n");
        else if(d==ceng) {
            if(n==pow(2,d-1)) printf("%d\n",a[n]);
            else {
                for(int i=pow(2,d-1);i<n;i++ ) printf("%d ",a[i]);
                printf("%d\n",a[n]);
            }
        }
        else {
            int i;
            for(i=pow(2,d-1);i<pow(2,d)-1;i++){
                printf("%d ",a[i]);
            }
            printf("%d\n",a[i]);
        }
    }
}
