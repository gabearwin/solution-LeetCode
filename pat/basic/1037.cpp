#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
    int G1,S1,K1,G2,S2,K2;
    scanf("%d.%d.%d",&G1,&S1,&K1);
    scanf("%d.%d.%d",&G2,&S2,&K2);
    int sum1=(G1*17+S1)*29+K1,sum2=(G2*17+S2)*29+K2;
    int sum=sum2-sum1;
    printf("%s",sum>=0?"":"-");
    sum=abs(sum);
    cout<<sum/(17*29)<<'.'<<sum%(17*29)/29<<'.'<<sum%(17*29)%29;
    return 0;
}
