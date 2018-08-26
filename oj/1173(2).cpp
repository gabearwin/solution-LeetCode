#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int i,m,a[100]={0},b[100]={0};
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        scanf("%d",&m);
        for(i=0;i<m;i++){
            scanf("%d",&b[i]);
        }
        for(i=0;i<m;i++){
            int j=0,ans=0,base=0,top=n,mid;
            while(base<=top){
                mid=(base+top)/2;
                if(a[mid]==b[i]) {ans=1;break;}
                else if(b[i]<a[mid]) top=mid-1;
                else base=mid+1;
            }
            if(ans==1) printf("YES\n");
            else printf("NO\n");
        }
    }
}
