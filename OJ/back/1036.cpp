#include<stdio.h>
int main(){
    int n,x,y,z;
    while(scanf("%d",&n)!=EOF){
        scanf("%d%d%d",&x,&y,&z);
        int ans1=0,ans2=0,ans3=0;
        for(int i=1;i<10;i++){
            for(int j=0;j<10;j++){
                int tmp1=(10000*i+x*1000+y*100+z*10+j)%n;
                int tmp2=(10000*i+x*1000+y*100+z*10+j)/n;
                if(tmp1==0&&tmp2>ans3){
                    ans1=i;
                    ans2=j;
                    ans3=tmp2;
                }
            }
        }
        if(ans3!=0)
        printf("%d %d %d\n",ans1,ans2,ans3);
        else printf("0\n");
    }
    return 0;
}
