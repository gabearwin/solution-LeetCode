#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=10000;
int a[maxn];
int cmp(int a,int b){
    if(a!=b) return a>b;
}
int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++) cin>>a[i];
    int n=1,m=N;
    for(int i=(int)sqrt(N);i>=1;i--){//确定m和n
        if(N%i==0) {n=i;break;}
    }
    m=N/n;
    //cout<<"m="<<m<<' '<<"n="<<n<<endl;
    sort(a,a+N,cmp);
    int row=0,column=0,cnt=0;
    int b[m][n];
    memset(b,-1,sizeof(b));
    while(cnt<N){//分别为向右、向下、向左、向上
        while(column<n&&b[row][column]==-1){
            b[row][column]=a[cnt++];
            column++;
        }
        column--;
        row++;
        while(row<m&&b[row][column]==-1){
            b[row][column]=a[cnt++];
            row++;
        }
        row--;
        column--;
        while(column>=0&&b[row][column]==-1){
            b[row][column]=a[cnt++];
            column--;
        }
        row--;
        column++;
        while(row>=0&&b[row][column]==-1){
            b[row][column]=a[cnt++];
            row--;
        }
        row++;
        column++;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(j==0) cout<<b[i][j];
            else cout<<' '<<b[i][j];
        }
        cout<<endl;
    }
    return 0;
}
