#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
const int maxn=100001;
typedef pair<int,int> P;
P p[maxn];
struct Node{
    int address, data;
};
int main(){
    int start,n,k;
    cin>>start>>n>>k;
    int address,data,next,i;
    for(i=0;i<n;i++) {
        cin>>address>>data>>next;
        p[address].first=data;
        p[address].second=next;
    }
    vector <Node> v;
    Node node;
    while(start!=-1){
        node.address=start;
        node.data=p[start].first;
        v.push_back(node);
        start=p[start].second;
    }
    int index;
    for(i=0,index=k;i<v.size()/k;i++,index+=k){
        reverse(v.begin()+index-k,v.begin()+index);
    }
    for(i=0;i<v.size()-1;i++){
        printf("%05d %d %05d\n",v[i].address,v[i].data,v[i+1].address);
    }
    printf("%05d %d -1\n",v[i].address,v[i].data);
    return 0;
}
