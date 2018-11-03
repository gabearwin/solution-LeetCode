#include<iostream>
using namespace std;
const int maxn=1000000;//弄大一点
int num[maxn],prime[maxn];
void Prime(){//素数表
    int cnt=0;
    for(int i=2;i<maxn;i++){
        if(num[i]==1) continue;
        prime[cnt++]=i;
        for(int j=2*i;j<maxn;j+=i) num[j]=1; //可以j从i²开始
    }
}
int main(){
    Prime();
    int m,n;
    cin>>m>>n;
    int first=1,cnt=0;
    for(int i=m-1;i<n;i++){
        if(cnt!=0&&cnt%10==0){cout<<endl;first=1; } //输出之前检查是否换行
        if(first){cout<<prime[i];cnt++;first=0; }
        else {cout<<' '<<prime[i];cnt++;}
    }
    return 0;
}
