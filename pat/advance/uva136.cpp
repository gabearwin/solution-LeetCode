#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;
typedef long long LL;
const int ugly[3]={2,3,5};
int main(){
    //������һ��ԽС���������ȼ�Խ������ȶ���
    priority_queue<LL,vector<LL>,greater<LL> > pq;
    set<LL> s;//����һ�����ϣ��ü���Ԫ��Ψһ�Դ洢����
    pq.push(1);
    s.insert(1);
    for(int i=1;;i++){
        LL top=pq.top();
        pq.pop();
        if(i==1500) {cout<<top<<endl;break;}
        for(int j=0;j<3;j++){
            LL temp=top*ugly[j];
            if(!s.count(temp)){//����temp���ڼ���set��
                s.insert(temp);
                pq.push(temp);
            }
        }
    }
    return 0;
}
