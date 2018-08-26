#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int n,a,b,c,m=0;
    int maxn=10001;
    int score[maxn]={0};
    cin>>n;
    while(n--){
        scanf("%d-%d %d",&a,&b,&c);
        score[a]+=c;
    }
    for(int i=0;i<maxn;i++){
        if(score[i]>score[m]) m=i;
    }
    cout<<m<<' '<<score[m];
    return 0;
}
