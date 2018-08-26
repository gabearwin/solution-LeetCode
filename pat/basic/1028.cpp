#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=100002;
struct Men{
    char name[10];
    int y,m,d;
    bool operator <(const Men &a)const{
        if(y!=a.y) return y<a.y;
        else if(m!=a.m) return m<a.m;
        else if(d!=a.d) return d<a.d;
    }
}v[maxn];
int main(){
    int n;
    cin>>n;
    Men men;
    //vector <Men> v;
    int y,m,d,cnt=0;
    for(int i=0;i<n;i++){
        scanf("%s%d/%d/%d",men.name,&y,&m,&d);
        int flag=1;
        if(y<1814) flag=0;
        else if(y==1814&&m<9) flag=0;
        else if(y==1814&&m==9&&d<6) flag=0;
        else if(y>2014) flag=0;
        else if(y==2014&&m>9) flag=0;
        else if(y==2014&&m==9&&d>6) flag=0;
        if(flag==1){
            men.y=y,men.m=m;men.d=d;
            v[cnt++]=men;
        }
    }
    if(cnt==0) cout<<0;
    else {
        sort(v,v+cnt);
        cout<<cnt<<' '<<v[0].name<<' '<<v[cnt-1].name;
    }
    return 0;
}
