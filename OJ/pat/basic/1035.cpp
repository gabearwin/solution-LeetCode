#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,a[100],b[100];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int i,j;
    for(i=0;i<n-1&&b[i+1]>=b[i];i++);//�ҵ���ͬԪ�ص����
    for(j=i+1;j<n&&a[j]==b[j];j++);//�ҵ���ͬԪ�ص��յ�
//    cout<<"j="<<j<<endl;
    if(j==n) {cout<<"Insertion Sort"<<endl;sort(a,a+i+2);}//��ͬԪ�ص��յ�������ж�Ϊ��������
    else{
        cout<<"Merge Sort"<<endl;
        int k=1,flag=1;
        while(flag){
            flag=0;
            for(i=0;i<n;i++){ //��֤�Ƿ�����Ŀ�������м䲽��
                if(a[i]!=b[i]){flag=1;break;}
            }
            k=k*2; //�鲢����Ԫ����
//            cout<<"k="<<k<<endl;
            for(i=0;i+k<=n-n%k;i+=k) //��ǰ��ĵ�Ԫ�鲢����
                sort(a+i,a+i+k);
//            for(i=0;i<n;i++) cout<<a[i]<<' ';
            sort(a+i,a+n); //ע��˴������治����Ԫ���ȵ�ҲҪ������3 9 0 5 1 7 3 ��k=4ʱ������Ҫ����
        }
    }
    cout<<a[0];
    for(i=1;i<n;i++) cout<<' '<<a[i];
    return 0;
}
