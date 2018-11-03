#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int L,N;
    while(scanf("%d%d",&L,&N)!=EOF){
        int i,a[601]={0},ans_L=0,ans_N=0;
        for(i=0;i<N;i++)
            scanf("%d",&a[i]);
        sort(a,a+N,cmp);
        for(i=0;i<N;i++){
            if(ans_L+a[i]>=L) {
                ans_N++;
                break;
            }
            ans_L+=a[i];
            ans_N++;
        }
        if(i==N) printf("impossible\n");
        else printf("%d\n",ans_N);
    }
    return 0;
}
