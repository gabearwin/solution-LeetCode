#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int t,k;
    cin>>t;
    int sum_0=0,cnt_0=0,cnt_1=0,sum_1=0,index=-1,sum_2=0;
    int cnt_3=0,sum_3=0,cnt_4=0,sum_4=0;
    while(t--){
        cin>>k;
        if(k%5==0){
            if(k%2==0) {sum_0+=k;cnt_0++;}
        }else if(k%5==1){
            cnt_1++;
            index=-index;
            sum_1+=index*k;
        }else if(k%5==2){
            sum_2++;
        }else if(k%5==3){
            cnt_3++;
            sum_3+=k;
        }else if(k%5==4){
            cnt_4++;
            sum_4=max(sum_4,k);
        }
    }
    if(cnt_0==0) cout<<'N';
    else cout<<sum_0;
    if(cnt_1==0) cout<<" N";
    else cout<<' '<<sum_1;
    if(sum_2==0) cout<<" N";
    else cout<<' '<<sum_2;
    if(cnt_3==0) cout<<" N";
    else printf(" %.1f",sum_3*1.0/cnt_3);
    if(cnt_4==0) cout<<" N";
    else cout<<' '<<sum_4;
    return 0;
}
