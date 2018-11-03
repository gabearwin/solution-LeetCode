#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;
typedef long long LL;
const int ugly[3]={2,3,5};
int main(){
    //定义了一个越小的整数优先级越大的优先队列
    priority_queue<LL,vector<LL>,greater<LL> > pq;
    set<LL> s;//定义一个集合，用集合元素唯一性存储丑数
    pq.push(1);
    s.insert(1);
    for(int i=1;;i++){
        LL top=pq.top();
        pq.pop();
        if(i==1500) {cout<<top<<endl;break;}
        for(int j=0;j<3;j++){
            LL temp=top*ugly[j];
            if(!s.count(temp)){//丑数temp不在集合set中
                s.insert(temp);
                pq.push(temp);
            }
        }
    }
    return 0;
}
