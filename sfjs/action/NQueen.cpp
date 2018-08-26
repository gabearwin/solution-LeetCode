#include<iostream>
#include<cmath>
using namespace std;

int N;
int queenPos[100];                          //queenPos[i]=j��ʾ��i���ʺ����i��j�С�i��j���Ǵ�0��ʼ

void NQueen(int k){                         //���������ã���0~k-1�лʺ��Ѿ��ںõ�����£��ڵ�k�м����Ļʺ�
    if(k == N){                             //N���ʺ��Ѿ��ں�
        for(int i=0; i<N; i++)
            cout << queenPos[i]+1 << ' ';
        cout << endl;
        return ;                            //������ǰ�ݹ顣����forѭ����
    }
    for(int i=0; i<N; i++){                 //�ڵ�k���г��Խ�k�ʺ����iλ����
        int j;
        for(j=0; j<k; j++){                 //�ʺ����iλ��ʱ��������λ���Ƿ���ѰںõĻʺ��ͻ
            if(queenPos[j]==i||abs(queenPos[j]-i)==abs(k-j))//����ͬһ�У����ڶԽ�����
                break;                      //��ͻ��������һ��i��λ��
        }
        if(j==k){                           //����iλ�ÿ��ԣ���������һ���ʺ�
            queenPos[k]=i;
            NQueen(k+1);
        }
    }
}
int main(){
    cin>>N;
    NQueen(0);                              //�ӵ�0�п�ʼ�ڻʺ�
    return 0;
}
