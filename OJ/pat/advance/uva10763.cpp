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
            pair<int,int> ex1=make_pair(a,b);//注意用法，是圆括号()
            pair<int,int> ex2=make_pair(b,a);
            if(mp[ex2]) mp[ex2]--;
            else mp[ex1]++;
            //if(!mp[ex2]) mp.erase(ex2);
            //不擦除会影响size大小。这里也可不擦除，但是后面输出之前要先统计非空的数量
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
