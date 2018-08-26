#include<stdio.h>
#include<algorithm>
using namespace std;
struct Goods{
    double j;//the weight
    double f;//price
    double s;//j/f
    bool operator < (const Goods &a) const{
        return s>a.s;
    }
}buf[1000];
int main(){
    int n;
    double m;
    while(scanf("%lf%d",&m,&n)!=EOF){
        if(m==-1&&n==-1) break;
        for( int i=0;i<n;i++){
            scanf("%lf%lf",&buf[i].j,&buf[i].f);
            buf[i].s=buf[i].j/buf[i].f;
        }
        sort(buf,buf+n);
        int idx=0;
        double ans=0;
        while(m>0&&idx<n){
            if(m>buf[idx].f){
                ans+=buf[idx].j;
                m-=buf[idx].f;
            }
            else{
                ans+=buf[idx].s*m;
                m=0;
            }
            idx++;
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}
