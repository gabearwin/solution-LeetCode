#include<stdio.h>
#include<algorithm>
using namespace std;
int a[35*35];
int main(){
    int m,n,cubi,cnt=0;
    while(~scanf("%d%d",&m,&n)&&m&&n){
        for(int i=0;i<m*n;i++) scanf("%d",&a[i]);
        sort(a,a+m*n);
        a[m*n]=0x7fffffff;
        scanf("%d",&cubi);
        double sum=cubi/100.0;
        int i=0;
        for(i=1;i<=m*n;i++){
            sum+=a[i-1];
            if(sum/i<=a[i]) break;
        }
        printf("Region %d\n",++cnt);
        printf("Water level is %.2lf meters.\n",sum/i);
        printf("%.2lf percent of the region is under water.\n\n",i*100.0/(m*n));
    }
}
