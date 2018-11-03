#include<stdio.h>
int main(){
int n,a[100],i,j,flag,temp;
while(scanf("%d",&n)!=EOF){
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }//输入数据
    for(i=0;i<n-1;i++){
        flag=0;
        for(j=n-1;j>i;j--){
        if(a[j]<a[j-1]){
            temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
            flag=1;
        }
        }
        if(flag==0){
            break;
        }
    }//冒泡排序主体
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
return 0;
}
