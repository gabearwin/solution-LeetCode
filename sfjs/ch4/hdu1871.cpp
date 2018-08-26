#include<iostream>
#include<algorithm>
using namespace std;
struct Room{
    int id,cnt,price;
    bool operator < (const Room &a) const{
        if(a.price!=price) return price<a.price;
    }
}room[101];
int main(){
    int T;
    cin>>T;
    while(T--){
        int c;
        cin>>c;
        for(int i=0;i<c;i++){
            cin>>room[i].id>>room[i].cnt>>room[i].price;
        }
        sort(room,room+c);
        int t,sum;
        cin>>t;
        while(t--){
            cin>>sum;
            int flag=0;
            for(int i=0;i<c;i++){
                if(room[i].cnt>=sum){
                    room[i].cnt-=sum;
                    flag=1;
                    cout<<room[i].id<<endl;
                    break;
                }
            }
            if(flag==0) cout<<"sorry"<<endl;
        }
    }
}
