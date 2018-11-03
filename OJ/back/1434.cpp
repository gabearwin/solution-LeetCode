#include<stdio.h>
#include<algorithm>
using namespace std;
struct TV{
    int ts;
    int te;
    bool operator < (const TV &a) const{
        return te<a.te;
    }
}buf[101];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0){
        int i;
        for(i=0;i<n;i++){
            scanf("%d%d",&buf[i].ts,&buf[i].te);
        }
        sort(buf,buf+n);
        int cnt=0,last_end=0;
        for(i=0;i<n;i++){
            if(buf[i].ts>=last_end){
                cnt++;
                last_end=buf[i].te;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
