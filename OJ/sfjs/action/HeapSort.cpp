#include<iostream>
using namespace std;

//arr是待调整的堆数组, len是数组的长度, elem是待调整的数组元素的位置
//本函数功能是根据数组arr构建大根堆
void HeapAdjust(int arr[],int len,int elem)
{
    int Child;
    for(;2*elem+1<len;elem=Child)
    {
        //子结点的位置=2*（父结点位置）+1
        Child=2*elem+1;
        //得到子结点中较大的结点
        if(Child<len-1&&arr[Child+1]>arr[Child]) ++Child;
        //如果较大的子结点大于父结点那么把较大的子结点往上移动，替换它的父结点
        if(arr[elem]<arr[Child])
            swap(arr[elem],arr[Child]);
        else
            break; //否则退出循环
    }
}

//堆排序算法
void HeapSort(int arr[],int len)
{
    //调整序列的前半部分元素，调整完之后第一个元素是序列的最大的元素
    //len/2-1是最后一个非叶节点，此处"/"为整除
    for(int elem=len/2-1;elem>=0;--elem)
        HeapAdjust(arr,len,elem);
    //从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素
    for(int i=len-1;i>0;--i)
    {
        //把第一个元素和当前的最后一个元素交换，
        //保证当前的最后一个位置的元素都是在现在的这个序列之中最大的
        swap(arr[0],arr[i]);
        //不断缩小调整heap的范围，每一次调整完毕保证第一个元素是当前序列的最大值
        HeapAdjust(arr,i,0);
    }
}
int main()
{
    int num[]={9,3,88,7,64,5,4,32,2,1,0,23,10,6,8};
    int len=sizeof(num)/sizeof(int);
    HeapSort(num,len);
    for(int i=0;i<len;++i)
        cout<<num[i]<<' ';
    return 0;
}
