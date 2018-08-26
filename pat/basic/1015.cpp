#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100000;
struct Stu{
    int id,de,cai,decai;
    bool operator <(const Stu &a)const{
        if(decai!=a.decai) return decai>a.decai;
        else if(de!=a.de) return de>a.de;
        else return id<a.id;
    }
}stu,stu1[maxn],stu2[maxn],stu3[maxn],stu4[maxn];
void out(Stu a[],int m){
    sort(a,a+m);
    for(int i=0;i<m;i++) cout<<a[i].id<<' '<<a[i].de<<' '<<a[i].cai<<endl;
}
int main(){
    int N,L,H;
    cin>>N>>L>>H;
    int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
    for(int i=0;i<N;i++){
        cin>>stu.id>>stu.de>>stu.cai;
        stu.decai=stu.de+stu.cai;
        if(stu.de>=L&&stu.cai>=L){
            if(stu.de>=H&&stu.cai>=H){
                stu1[cnt1++]=stu;
            }else if(stu.de>=H&&stu.cai<H){
                stu2[cnt2++]=stu;
            }else if(stu.de<H&&stu.cai<H&&stu.de>=stu.cai){
                stu3[cnt3++]=stu;
            }else{
                stu4[cnt4++]=stu;
            }
        }
    }
    cout<<cnt1+cnt2+cnt3+cnt4<<endl;
    out(stu1,cnt1);
    out(stu2,cnt2);
    out(stu3,cnt3);
    out(stu4,cnt4);
    return 0;
}
