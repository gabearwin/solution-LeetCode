#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct Yue{
    double kc,sj,dj;
    bool operator < (Yue &y){if(dj!=y.dj) return dj>y.dj; }
}yue[1000];
int main(){
    int n,d;
    cin>>n>>d;
    for(int i=0;i<n;i++) cin>>yue[i].kc;
    for(int i=0;i<n;i++) {
        cin>>yue[i].sj;
        yue[i].dj=yue[i].sj/yue[i].kc;
    }
    sort(yue,yue+n);
    double sy=0;
    for(int i=0;i<n&&d>0;i++){
        if(d>=yue[i].kc) {sy+=yue[i].sj;d-=yue[i].kc;}
        else{sy+=d*yue[i].dj;d=0;}
    }
    printf("%.2f\n",sy);
    return 0;
}
