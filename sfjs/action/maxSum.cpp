#include<iostream>
using namespace std;

const int maxn = 101;
int D[maxn][maxn];                  //�洢�������е�i�е�j�е���ֵ��i��j����1��ʼ
int n;                              //����������

int maxSum(int i, int j){           //��D(i,j)���ױߵĸ���·���У����·��������֮�͡�
    if(i == n)                      //D(i,j)���������εױ���
        return D[i][j];
    int x = maxSum(i+1,j);
    int y = maxSum(i+1,j+1);
    return max(x,y)+D[i][j];        //D(i,j)���ױ����Ž�
}

int main(){
    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=i; j++)
            cin>>D[i][j];
    cout<<maxSum(1,1)<<endl;        //�������ζ��㵽�ױ����Ž�
    return 0;
}
