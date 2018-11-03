#include<iostream>
using namespace std;
char out(int b,int c,int j){
    int maxn=max(max(b,c),j);
    if(maxn==b) return 'B';
    else if(maxn==c) return 'C';
    else if(maxn==j) return 'J';
}
int main(){
    int n;
    cin>>n;
    char a,b;
    int cnt=0,cnt1=0,cnt2=0,cnt1_b=0,cnt1_c=0,cnt1_j=0,cnt2_b=0,cnt2_c=0,cnt2_j=0;
    while(n--){
        cin>>a>>b;
        if(a==b) cnt++;
        else{
            if(a=='B'){
                if(b=='C') {cnt1++;cnt1_b++;}
                if(b=='J') {cnt2++;cnt2_j++;}
            }
            if(a=='C'){
                if(b=='J') {cnt1++;cnt1_c++;}
                if(b=='B') {cnt2++;cnt2_b++;}
            }
            if(a=='J'){
                if(b=='B') {cnt1++;cnt1_j++;}
                if(b=='C') {cnt2++;cnt2_c++;}
            }
        }
    }
    cout<<cnt1<<' '<<cnt<<' '<<cnt2<<endl;
    cout<<cnt2<<' '<<cnt<<' '<<cnt1<<endl;
    cout<<out(cnt1_b,cnt1_c,cnt1_j)<<' '<<out(cnt2_b,cnt2_c,cnt2_j)<<endl;
    return 0;
}
