#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1010;
int num[maxn], maxLen[maxn];
int main(){
    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> num[i];
        maxLen[i] = 1;                                      //初始化以num[i]为结尾的最长上升子序列长度为1
    }
    for(int i=2; i<=N; i++){                                //从第二个数开始，求以num[i]为终点的最长上升子序列的长度
        for(int j=1; j<i; j++)
            if(num[j] < num[i])                             //查看以num[j]为终点的最长上升子序列长度，并更新maxLen[i]的值
                maxLen[i] = max(maxLen[i], maxLen[j]+1);
    }
    cout << *max_element(maxLen+1,maxLen+N+1) << endl;
    return 0;
}
