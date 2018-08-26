#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int c,i;
    while(scanf("%d",&c)!=EOF){
        for(i=0;i<c;i++){
            int j,a[102]={0},n,v,w;
            scanf("%d %d %d",&n,&v,&w);
            for(j=0;j<n;j++){
                scanf("%d",&a[j]);
            }
            sort(a,a+n);
            int ans_j=0,ans_w=0;
            for(j=0;j<n;j++){
                if((ans_w+a[j])>(ans_j+1)*w) break;
                ans_w+=a[j];
                ans_j++;
            }
            if(ans_j==0) printf("0 0.00\n");
            else printf("%d %.2f\n",v*ans_j,ans_w*1.00/(100*ans_j));
        }
    }
    return 0;
}
