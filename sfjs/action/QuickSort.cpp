#include<iostream>
using namespace std;

//������a,��a[s]��a[e]���п���
void QuickSort(int a[], int s, int e){
    if(s >= e) return;
    int key = a[s];
    int left = s, right = e;
    while(left != right){
        while(left<right && a[right]>=key)  //���������ҵ���keyС��
            right--;
        a[left] = a[right];
        while(left<right && a[left]<=key)   //�������ҵ���key���
            left++;
        a[right] = a[left];
    }
    a[left] = key;                          //��ʱleft��right���
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
