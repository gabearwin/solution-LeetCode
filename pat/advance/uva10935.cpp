#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
int main(){
    int n;
    queue<int> q;
    while(cin>>n&&n){
        int first=1;
        cout<<"Discarded cards:";
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        while(q.size()>1){
            if(first==1){printf(" %d",q.front()); first=0;}
            else printf(", %d",q.front());
            q.pop();
            int p=q.front();
            q.pop();
            q.push(p);
        }
        printf("\nRemaining card: %d\n",q.front());
        q.pop();
    }
    return 0;
}


//Discarded cards: 1, 3, 5, 7, 4, 2
//Remaining card: 6
