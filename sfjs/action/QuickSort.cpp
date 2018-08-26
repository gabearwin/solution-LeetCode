#include<iostream>
using namespace std;

//对数组a,从a[s]到a[e]进行快排
void QuickSort(int a[], int s, int e){
    if(s >= e) return;
    int key = a[s];
    int left = s, right = e;
    while(left != right){
        while(left<right && a[right]>=key)  //从右往左找到比key小的
            right--;
        a[left] = a[right];
        while(left<right && a[left]<=key)   //从左到右找到比key大的
            left++;
        a[right] = a[left];
    }
    a[left] = key;                          //此时left和right相等
    QuickSort(a,s,left-1);
    QuickSort(a,left+1,e);
}

int main(){
    int a[]={5,7,9,1,8,4,6,10,3,2};
    int length = sizeof(a)/sizeof(int);
    QuickSort(a,0,length-1);
    for(int i=0;i<length;i++)
        cout<<a[i]<<' ';
    return 0;
}
