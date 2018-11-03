#include<iostream>
using namespace std;
struct Men{
    char zkzh[15];
    int ks;
}men[1001];
int main(){
    int n,sj;
    Men M;
    cin>>n;
    while(n--){
        cin>>M.zkzh>>sj>>M.ks;
        men[sj]=M;
    }
    int m,k;
    cin>>m;
    while(m--){
        cin>>k;
        cout<<men[k].zkzh<<' '<<men[k].ks<<endl;
    }
    return 0;
}
