#include<iostream>
using namespace std;
const int maxn = 101;
int n;
int D[maxn][maxn];
int maxSum[maxn][maxn];         //��D(i,j)���ױߵĸ���·���У����·��������֮�͡�
int main(){
    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=i; j++)
            cin >> D[i][j];
    for(int i=1; i<=n; i++)
        maxSum[n][i] = D[n][i];
    for(int i=n-1; i>=1; i--)
        for(int j=1; j<=i; j++)
            maxSum[i][j] = max(maxSum[i+1][j],maxSum[i+1][j+1]) + D[i][j];
    cout << maxSum[1][1] <<endl;
    return 0;
}
