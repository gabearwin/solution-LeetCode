#include<stdio.h>
int main(){
int n,a[100],i,j,flag,temp;
while(scanf("%d",&n)!=EOF){
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }//��������
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
    }//ð����������
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
return 0;
}
