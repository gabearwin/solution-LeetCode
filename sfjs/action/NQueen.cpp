#include<iostream>
#include<cmath>
using namespace std;

int N;
int queenPos[100];                          //queenPos[i]=j表示第i个皇后放在i行j列。i，j都是从0开始

void NQueen(int k){                         //函数的作用：在0~k-1行皇后已经摆好的情况下，摆第k行及其后的皇后
    if(k == N){                             //N个皇后已经摆好
        for(int i=0; i<N; i++)
            cout << queenPos[i]+1 << ' ';
        cout << endl;
        return ;                            //结束当前递归。继续for循环。
    }
    for(int i=0; i<N; i++){                 //在第k行中尝试将k皇后放在i位置上
        int j;
        for(j=0; j<k; j++){                 //皇后放在i位置时，检查这个位置是否和已摆好的皇后冲突
            if(queenPos[j]==i||abs(queenPos[j]-i)==abs(k-j))//不在同一列；不在对角线上
                break;                      //冲突，尝试下一个i的位置
        }
        if(j==k){                           //放在i位置可以，继续放下一个皇后
            queenPos[k]=i;
            NQueen(k+1);
        }
    }
}
int main(){
    cin>>N;
    NQueen(0);                              //从第0行开始摆皇后
    return 0;
}
