#include<iostream>
using namespace std;

const int maxn = 101;
int sum[maxn][maxn];                //存储已经算出的maxSum值
int D[maxn][maxn];
int n;

int maxSum(int i, int j){           //从D(i,j)到底边的各条路径中，最佳路径的数字之和。
    if(sum[i][j] != -1)             //此maxSum已算出过
        return sum[i][j];
    if(i == n)
        sum[i][j] = D[i][j];
    else{
        int x = maxSum(i+1,j);
        int y = maxSum(i+1,j+1);
        sum[i][j] = max(x,y)+D[i][j];
    }
    return sum[i][j];
}

int main(){
    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=i; j++){
            cin>>D[i][j];
            sum[i][j] = -1;         //均初始化为-1
        }
    cout<<maxSum(1,1)<<endl;
    return 0;
}
