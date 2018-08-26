#include<iostream>
using namespace std;
#include<algorithm>
const int maxn=100000;
typedef struct{
    int x,y,num;
}men;
men p[maxn];
int cmp(men a,men b){
    if(a.x!=b.x) return a.x<b.x;
    else return a.y<b.y;
}
int main(){
    int T,N,i,block=0;
    cin>>T;
    while(T--){
        cin>>N;
        for(i=0;i<N;i++){
            cin>>p[i].x>>p[i].y;
            p[i].num=i;
        }
        sort(p,p+N,cmp);
        int xx=p[0].x,yy=p[0].y,cnt=1;
        for(i=1;i<N;i++){
            if(p[i].x>xx&&p[i].y>yy){
                xx=p[i].x,yy=p[i].y;
                cnt++;
            }else{
                p[i].num=-1;
            }
        }
        if(block++) cout<<endl;
        cout<<cnt<<endl;
        for(i=0;i<N;i++){
            if(p[i].num!=-1){
                cout<<p[i].num+1<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}
