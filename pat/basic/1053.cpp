#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int n,d;
    double e;
    cin>>n>>e>>d;
    int cnt=0,cnt1=0,cnt2=0;
    for(int j=0;j<n;j++){
        int k;
        cnt=0;
        cin>>k;
        double E[1000];
        for(int i=0;i<k;i++){
            cin>>E[i];
            if(E[i]<e) cnt++;
        }
        if(cnt>=(k/2+1)){
            if(k>d) cnt2++;
            else cnt1++;
        }
    }
    printf("%.1f%% %.1f%%\n",cnt1*100.0/n,cnt2*100.0/n);
    return 0;
}
