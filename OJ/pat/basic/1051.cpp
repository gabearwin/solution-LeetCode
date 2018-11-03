#include<stdio.h>
#include<math.h>
int main(){
    double r1,p1,r2,p2;
    while(scanf("%lf %lf %lf %lf",&r1,&p1,&r2,&p2)!=EOF){
        double a=r1*r2*cos(p1+p2),b=r1*r2*sin(p1+p2);
        if(-0.005<a&&a<0){
            printf("0.00");
        }else{
            printf("%.2lf",a);
        }
        if(-0.005<b&&b<0){
            printf("+0.00i\n");
        }else if(b>=0){
            printf("+%.2lfi\n",b);
        }else{
            printf("%.2lfi\n",b);
        }
    }
    return 0;
}
