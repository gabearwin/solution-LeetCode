#include<iostream>
using namespace std;
const int maxn = 1001;                      //�������ֵ
int M,N,K=0;                                //M��N�У�·����K�����
int D[maxn][maxn];                          //�洢ԭʼ����ֵ
int dp[maxn][maxn];                         //��D[0][0]��D[i][j]·����Сֵ
int mp[maxn];                               //����·���еĽ��ֵ
int main(){
    cin >> M >> N;
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++)
            cin >> D[i][j];
    dp[0][0]=D[0][0];
    for(int i=1; i<M; i++)
        dp[i][0] = dp[i-1][0]+ D[i][0];     //���ڵ�һ�еĵ�D[i][0]��ֻ�����Ǵ�����ĵ�D[i-1][0]������
    for(int j=1; j<N; j++)
        dp[0][j] = dp[0][j-1]+ D[0][j];     //���ڵ�һ�еĵ�D[0][j]��ֻ�����Ǵ���ߵĵ�D[0][j-1]������
    for(int i=1; i<M; i++)
        for(int j=1; j<N; j++)              //��D[i][j]���Ǵ�D[i][j-1]��D[i-1][j]��С�Ķ���
            dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + D[i][j];
    int i=M-1,j=N-1;
    mp[K++]=D[i][j];
    while(i>=0 && j>=0){                    //������·���ϵĵ�
        if(i==0 && j==0){
            break;
        } else if(i==0){                    //�ڵ�һ���ϣ���ô��һ����ֻ������ߵĵ�
            mp[K++]=D[i][j-1];
            j--;
        } else if(j==0){                    //�ڵ�һ���ϣ���ô��һ����ֻ��������ĵ�
            mp[K++]=D[i-1][j];
            i--;
        } else {                            //���������ߺ������dp��С��Ӧ���Ǹ���D
            if(dp[i-1][j]<dp[i][j-1]){
                mp[K++]=D[i-1][j];
                i--;
            } else {
                mp[K++]=D[i][j-1];
                j--;
            }
        }
    }
    for(int i=K-1;i>=0;i--){
        cout<<mp[i];
        if(i!=0) cout<<"->";
    }
    cout << endl << dp[M-1][N-1] <<endl;
    return 0;
}

/*
3 4
2 0 11 1
4 3 6 12
7 10 9 5
*/
