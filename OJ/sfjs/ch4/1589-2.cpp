#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=35;
int a[maxn*maxn],n,m;

int main(){
    for(int kase=1;scanf("%d%d",&n,&m),n&&m;kase++){
        n*=m;
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        a[n]=0x7fffffff;
        int k;
        double sum;
        scanf("%lf",&sum); sum/=100.0;
        for(k=1;k<=n;k++){
            sum+=a[k-1];
            if(sum/k<=a[k]) break;
        }
        printf("Region %d\n",kase);
        printf("Water level is %.2lf meters.\n",sum/k);
        printf("%.2lf percent of the region is under water.\n\n",k*100.0/n);
    }
}
