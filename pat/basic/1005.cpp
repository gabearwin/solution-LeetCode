#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int a[100],i=0,temp=0;
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        for(i=0;i<n;i++){
            if(a[i]!=0){
                temp=a[i];
                while(temp!=1){
                    if(temp%2==0){
                        temp=temp/2;
                    }
                    else if(temp%2==1){
                        temp=temp*3+1;
                        temp=temp/2;
                    }
                    for(int j=0;j<n;j++){
                        if(a[j]==temp){a[j]=0;}
                    }
                }
            }
        }
        sort(a,a+n);
        int flag=1;
        for(i=n-1;i>=0&&a[i]!=0;i--){
            if(flag>=1){
                printf("%d",a[i]);
                flag--;
            }else{
                printf(" %d",a[i]);
            }
        }
    }
    return 0;
}
