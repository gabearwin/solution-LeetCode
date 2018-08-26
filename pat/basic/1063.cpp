#include<stdio.h>
#include<math.h>
int main(){
    int n;
    scanf("%d",&n);
    int a,b,c,great=0;
    for(int i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        c=a*a+b*b;
        if(c>great) great=c;
    }
    printf("%.02lf\n",sqrt(great)*1.0);
    return 0;
}
