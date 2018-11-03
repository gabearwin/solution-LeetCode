#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
const int maxn=100001;
struct Node{
    int address, data, next;
}node[maxn];
int main(){
    int first,n,k,i;
    cin>>first>>n>>k;
    for(i=0;i<n;i++) cin>>node[i].address>>node[i].data>>node[i].next;
    vector <Node> v;
    while(first!=-1){
        for(i=0;i<n;i++){
            if(node[i].address==first) {
                v.push_back(node[i]);
                first=node[i].next;
                break;
            }
        }
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
