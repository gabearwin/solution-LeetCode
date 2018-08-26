#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1000];
int main(){
    int m,n,cubi,cnt=0;
    while(~scanf("%d%d",&m,&n)&&m&&n){
        for(int i=0;i<m*n;i++) scanf("%d",&a[i]);
        scanf("%d",&cubi);
        double cub=cubi*1.0/100;
        sort(a,a+m*n);
        //for(int i=0;i<m*n;i++) printf("%d ",a[i]);
        int sum=0,i=0,last=0;
        double high=0.0,percent=0.0;
        for(i=1;i<m*n&&(cub-sum)>0;i++){
            last=sum;
            sum+=i*(a[i]-a[i-1]);
        }
        //printf("%d %d %d\n",last,sum,i);
        if(cub==0){high=a[0];percent=0; }
        else if(i==m*n&&(cub-sum)>0){//水填满了最高海拔的格子，还有多的水
            high=(cub-sum)*1.0/i+a[i-1];
            percent=100;
        }
        else {
            /*水没有填满最高海拔的格子，在中间时就不够用了。
            这里用到sum的上一次结果，所以上面for循环中用了last保存。*/
            high=(cub-last)*1.0/(i-1)+a[i-2];
            percent=(i-1)*1.0/(m*n)*100;
        }
        printf("Region %d\n",++cnt);
        printf("Water level is %.2f meters.\n",high);
        printf("%.2f percent of the region is under water.\n\n",percent);//注意空行在最后面
    }
    return 0;
}
