#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct Stu{
    char name[55];
    int score,id;
    bool operator < (const Stu &a) const{
        if(score!=a.score) return score>a.score;
        else return id<a.id;
    }
}stu[310],xu[310];
int n;
void out(Stu a[],int n){
    for(int i=0;i<n;i++) cout<<a[i].name<<' '<<a[i].score<<endl;
}
int main(){
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>stu[i].name>>stu[i].score;
            stu[i].id=i;
        }
        for(int i=0;i<n;i++){
            cin>>xu[i].name>>xu[i].score;
        }
        sort(stu,stu+n);
        int flag1=1,flag2=1;
        for(int i=0;i<n;i++){
            if(stu[i].score!=xu[i].score){
                cout<<"Error"<<endl;
                out(stu,n);
                flag2=0;
                break;
            }
        }
        if(flag2==0) continue;
        for(int i=0;i<n;i++){
            if(strcmp(stu[i].name,xu[i].name)!=0){
                cout<<"Not Stable"<<endl;
                out(stu,n);
                flag1=0;
                break;
            }
        }
        if(flag1==0) continue;
        cout<<"Right"<<endl;
    }
    return 0;
}
