#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int D,I;
    while(cin>>D>>I){
        int k=1; //k�����һ��С�����ߵ����
        for(int i=0;i<D-1;i++){
            if(I%2){
                k=2*k; //����������
                I=(I+1)/2; //�������ߵĵ�(I+1)/2��
            }else{
                k=2*k+1; //ż��������
                I=I/2; //�������ߵĵ�I/2��
            }
        }
        cout<<k<<endl;
    }
    return 0;
}
