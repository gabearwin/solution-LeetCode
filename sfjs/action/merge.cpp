#include<iostream>
using namespace std;

int a[10]={5,7,9,1,8,4,6,10,3,2},b[10];

//将数组a的局部a[s,m]和a[m+1,e]合并到temp,并保证temp有序，然后再拷贝回a[s,m]
void Merge(int a[], int s, int m, int e, int temp[]){
    int pb=0;
    int p1=s, p2=m+1;
    while(p1<=m && p2<=e){
        if(a[p2] < a[p1])
            temp[pb++] = a[p2++];
        else
            temp[pb++] = a[p1++];
    }
    while(p1<=m)
        temp[pb++] = a[p1++];
    while(p2<=e)
        temp[pb++] = a[p2++];
    for(int i=0; i<pb; i++){
        a[s+i] = temp[i];
    }
}
//对数组a，将a[s]到a[e]归并排序
void MergeSort(int a[], int s, int e, int temp[]){
    if(s < e){
        int m = s +(e-s)/2;
        MergeSort(a,s,m,temp);
        MergeSort(a,m+1,e,temp);
        Merge(a,s,m,e,temp);
    }
}
int main(){
    int length = sizeof(a)/sizeof(int);
    MergeSort(a,0,length-1,b);
    for(int i=0;i<length;i++)
        cout<<a[i]<<' ';
    return 0;
}
