#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct ys{
    int id=0,weight=0,zt=0;
    bool operator < (const ys &a) const{
        if(weight!=a.weight) return weight>a.weight;
        else return id<a.id;
    }
}ys1[2002],ys2[2002],ys3[2002];
int main(){
    int n;
    while(cin>>n){
        char s[5];
        int a,b,cnt=0,num1=0,num2=0,num3=0,out1=0,out2=0,out3=0;
        while(n--){
            cin>>s;
            if(s[0]=='I'){
                cin>>a>>b;
                cnt++;
                if(a==1){ys1[num1].weight=b;ys1[num1].id=cnt;ys1[num1].zt=1;num1++; }
                if(a==2){ys2[num2].weight=b;ys2[num2].id=cnt;ys2[num2].zt=1;num2++; }
                if(a==3){ys3[num3].weight=b;ys3[num3].id=cnt;ys3[num3].zt=1;num3++; }
            }else{
                cin>>a;
                if(a==1){
                    if(out1+1-num1>0){cout<<"EMPTY"<<endl;}
                    else {
                        out1++; sort(ys1,ys1+num1);
                        for(int i=0;i<num1;i++){
                            if(ys1[i].zt==1){
                                cout<<ys1[i].id<<endl;
                                ys1[i].zt=0;
                                break;
                            }
                        }
                    }
                }if(a==2){
                    if(out2+1-num2>0){cout<<"EMPTY"<<endl;}
                    else {
                        out2++; sort(ys2,ys2+num2);
                        for(int i=0;i<num2;i++){
                            if(ys2[i].zt==1){
                                cout<<ys2[i].id<<endl;
                                ys2[i].zt=0;
                                break;
                            }
                        }
                     }
                }if(a==3){
                    if(out3+1-num3>0){cout<<"EMPTY"<<endl;}
                    else {out3++; sort(ys3,ys3+num3);
                        for(int i=0;i<num3;i++){
                            if(ys3[i].zt==1){
                                cout<<ys3[i].id<<endl;
                                ys3[i].zt=0;
                                break;
                            }
                        }
                     }
                }
            }
        }
    }
    return 0;
}
