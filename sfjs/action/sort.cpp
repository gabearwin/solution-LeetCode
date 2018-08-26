#include<iostream>
using namespace std;
/*ð������*/
//����һ���Ӻ���ǰ����������ǰ������
void BubbleSort(int a[],int n){
    for(int i=n-1;i>0;--i){
        for(int j=0;j<i;j++){
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
        }
    }
}

//����������ǰ����ǰ�����򣬺�������
void BubbleSort2(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j--){
            if(a[j]<a[j-1])
                swap(a[j],a[j-1]);
        }
    }
}
//���������Է���һ�Ͷ��ĸĽ�����Ҫ�Ǽ����˱����ж��ڲ�ѭ���Ƿ�ִ�У��������ж���ʣ�µ�Ԫ���Ƿ�����
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

/*ѡ������*/
//ÿ�ζ���������ѡ��һ����С�ķŵ�Ӧ�е�λ��
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

/*��������*/
//ÿ��ȡһ�������е�����������뵽����������
void InsertSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j>0&&a[j]<a[j-1];j--)
            swap(a[j],a[j-1]);
    }
}

/*���ֲ���*/
//�ڰ���cnt��Ԫ�ص������������a�У�����Ԫ��p������ҵ���Ԫ�أ�����Ԫ���±ꣻ���򷵻�-1
int BinarySearch(int a[],int cnt,int p){
    int left=0,right=cnt-1;
    while(left<=right){
        int mid=(left+right)/2;//Ϊ�˷�ֹ(left+right)�������������һ��д�� int mid=left+(right-left)/2;
        if(p>a[mid])
            left=mid+1;
        else if(p<a[mid])
            right=mid-1;
        else return mid;
    }
    return -1;
}

/*lower_bound�����ö��ַ�ʵ��*/
//lower_bound(__first,__last,const val)�������ص��Ǵ�first��last�Ǽ������У���һ�����ڻ��ߵ���val��Ԫ�صĵ�ַ��������ֱ�ӷ��ظ�Ԫ�ص��±ꡣ
int LowerBound(int a[],int cnt,int val){
    int left=0,right=cnt-1;
    int pos=-1;         //������¼���ڻ����valֵ���±�
    while(left<=right){
        int mid=(left+right)/2;
        if(a[mid]<val)
            left=mid+1;
        else{           //�м�ֵ���ڻ��ߵ���val������pos��Ȼ��������ҡ�
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
