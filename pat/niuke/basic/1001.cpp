#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int m,n,k;
    while(scanf("%d%d%d",&m,&n,&k)!=EOF){
        int a[25][25]={0},b[1000]={0},i,j,p=0,sum=0;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                scanf("%d",&a[i][j]);
                b[p++]=a[i][j];
            }
        }
        sort(b,b+p,cmp);
        int a1=0,b1=0,a2=0,b2=0;
        p=0;
        while(b[p]!=0){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(a[i][j]==b[p]){
                        a2=i+1;
                        b2=j+1;
                    }
                }
            }
            int flag=0;
            if(a1==0){
                if(2*a2+1<=k) {k-=a2+1;a1=a2;b1=b2;flag=1;}
                else{flag=0;}
            }else{
                if(abs(a2-a1)+abs(b2-b1)+1+a2<=k)
                {k-=abs(a2-a1)+abs(b2-b1)+1;
                a1=a2;b1=b2;flag=1;}
                else{flag=0;}
            }
            if(flag==1){
                sum+=b[p];
            }else{
                break;
            }
            p++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
