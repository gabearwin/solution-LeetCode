#include<iostream>
using namespace std;

const int maxn = 101;
int D[maxn][maxn];                  //存储三角形中第i行第j列的数值，i、j均从1开始
int n;                              //三角形行数

int maxSum(int i, int j){           //从D(i,j)到底边的各条路径中，最佳路径的数字之和。
    if(i == n)                      //D(i,j)就在三角形底边上
        return D[i][j];
    int x = maxSum(i+1,j);
    int y = maxSum(i+1,j+1);
    return max(x,y)+D[i][j];        //D(i,j)到底边最优解
}

int main(){
    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=i; j++)
            cin>>D[i][j];
    cout<<maxSum(1,1)<<endl;        //从三角形顶点到底边最优解
    return 0;
}
