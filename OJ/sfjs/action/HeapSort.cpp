#include<iostream>
using namespace std;

//arr�Ǵ������Ķ�����, len������ĳ���, elem�Ǵ�����������Ԫ�ص�λ��
//�����������Ǹ�������arr���������
void HeapAdjust(int arr[],int len,int elem)
{
    int Child;
    for(;2*elem+1<len;elem=Child)
    {
        //�ӽ���λ��=2*�������λ�ã�+1
        Child=2*elem+1;
        //�õ��ӽ���нϴ�Ľ��
        if(Child<len-1&&arr[Child+1]>arr[Child]) ++Child;
        //����ϴ���ӽ����ڸ������ô�ѽϴ���ӽ�������ƶ����滻���ĸ����
        if(arr[elem]<arr[Child])
            swap(arr[elem],arr[Child]);
        else
            break; //�����˳�ѭ��
    }
}

//�������㷨
void HeapSort(int arr[],int len)
{
    //�������е�ǰ�벿��Ԫ�أ�������֮���һ��Ԫ�������е�����Ԫ��
    //len/2-1�����һ����Ҷ�ڵ㣬�˴�"/"Ϊ����
    for(int elem=len/2-1;elem>=0;--elem)
        HeapAdjust(arr,len,elem);
    //�����һ��Ԫ�ؿ�ʼ�����н��е��������ϵ���С�����ķ�Χֱ����һ��Ԫ��
    for(int i=len-1;i>0;--i)
    {
        //�ѵ�һ��Ԫ�غ͵�ǰ�����һ��Ԫ�ؽ�����
        //��֤��ǰ�����һ��λ�õ�Ԫ�ض��������ڵ��������֮������
        swap(arr[0],arr[i]);
        //������С����heap�ķ�Χ��ÿһ�ε�����ϱ�֤��һ��Ԫ���ǵ�ǰ���е����ֵ
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
