#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
int main(){
    map<pair<int,int>,int> mp;
    int n;
    while(cin>>n&&n){
        mp.clear();
        while(n--){
            int a,b;
            cin>>a>>b;
            pair<int,int> ex1=make_pair(a,b);//ע���÷�����Բ����()
            pair<int,int> ex2=make_pair(b,a);
            if(mp[ex2]) mp[ex2]--;
            else mp[ex1]++;
            //if(!mp[ex2]) mp.erase(ex2);
            //��������Ӱ��size��С������Ҳ�ɲ����������Ǻ������֮ǰҪ��ͳ�Ʒǿյ�����
        }
        int flag=1;
        map<pair<int,int>,int>::iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            if(it->second!=0) {flag=0;break;}
        }
        printf("%s\n",flag==1?"YES":"NO");
        //printf("%s\n",mp.size()?"NO":"YES");
    }
    return 0;
}
