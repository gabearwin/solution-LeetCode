#include<iostream>
using namespace std;
/*冒泡排序*/
//方法一：从后往前，后面有序，前面无序
void BubbleSort(int a[],int n){
    for(int i=n-1;i>0;--i){
        for(int j=0;j<i;j++){
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
        }
    }
}

//方法二：从前往后，前面有序，后面无序
void BubbleSort2(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j--){
            if(a[j]<a[j-1])
                swap(a[j],a[j-1]);
        }
    }
}
//方法三：对方法一和二的改进，主要是加入了变量判断内层循环是否执行，这样就判断了剩下的元素是否有序。
void BubbleSort3(int a[],int n){
    for(int i=0;i<n-1;i++){
        int flag=1;
        for(int j=n-1;j>i;j--){
            if(a[j]<a[j-1]){
                swap(a[j],a[j-1]);
                flag=0;
            }
        }
        if(flag)
            return;
    }
}

/*选择排序*/
//每次都在无序中选择一个最小的放到应有的位置
void SelectSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int mini=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[mini])
                mini=j;
        }
        swap(a[i],a[mini]);
    }
}

/*插入排序*/
//每次取一个无序中的数，将其插入到有序序列中
void InsertSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j>0&&a[j]<a[j-1];j--)
            swap(a[j],a[j-1]);
    }
}

/*二分查找*/
//在包含cnt个元素的有序递增数组a中，查找元素p。如果找到此元素，返回元素下标；否则返回-1
int BinarySearch(int a[],int cnt,int p){
    int left=0,right=cnt-1;
    while(left<=right){
        int mid=(left+right)/2;//为了防止(left+right)过大溢出，我们一般写成 int mid=left+(right-left)/2;
        if(p>a[mid])
            left=mid+1;
        else if(p<a[mid])
            right=mid-1;
        else return mid;
    }
    return -1;
}

/*lower_bound函数用二分法实现*/
//lower_bound(__first,__last,const val)函数返回的是从first到last非减有序中，第一个大于或者等于val的元素的地址。这里我直接返回该元素的下标。
int LowerBound(int a[],int cnt,int val){
    int left=0,right=cnt-1;
    int pos=-1;         //用来记录大于或等于val值的下标
    while(left<=right){
        int mid=(left+right)/2;
        if(a[mid]<val)
            left=mid+1;
        else{           //中间值大于或者等于val，更新pos，然后继续查找。
            pos=mid;
            right=mid-1;
        }
    }
    return pos;
}

int main(){
    int a[]={2,9,1,5,2,10,3,7,4,-1,66,0};
    InsertSort(a,12);
    for(int i=0;i<12;i++)
        cout<<a[i]<<' ';
    int x=lower_bound(a,a+12,8)-a;
    int y=LowerBound(a,12,8);
    cout<<endl<<a[x]<<' '<<a[y]<<endl;
    return 0;
}
