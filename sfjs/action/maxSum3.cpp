#include<iostream>
using namespace std;
const int maxn = 101;
int n;
int D[maxn][maxn];
int main(){
    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=i; j++)
            cin >> D[i][j];
    int *maxSum = D[n];             //maxSumָ���n�У����õ�n�еĿռ�洢���
    for(int i=n-1; i>=1; i--)
        for(int j=1; j<=i; j++)
            maxSum[j] = max(maxSum[j],maxSum[j+1]) + D[i][j];
    cout << maxSum[1] <<endl;
    return 0;
}
