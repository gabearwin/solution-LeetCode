#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct E{
    char xue[10];
    char name[10];
    int score;
}buf[100001];
bool cmp1(E a,E b){
    return strcmp(a.xue,b.xue)<0;
}
bool cmp2(E a,E b){
    int tmp= strcmp(a.name,b.name);
    if(tmp!=0)return tmp<0;
    else{return strcmp(a.xue,b.xue)<0;}
}
bool cmp3(E a,E b){
    if(a.score!=b.score) return a.score<b.score;
    else{return strcmp(a.xue,b.xue)<0;}
}
int main(){
    int n,c,m=0,i,j=0,cnt=1;
    while (scanf("%d %d",&n,&c)!=EOF&&n!=0){
        for(i=0;i<n;i++){
            scanf("%s %s %d",buf[i].xue,buf[i].name,&buf[i].score);
        }
        if(c==1){sort(buf,buf+n,cmp1);}
        if(c==2){sort(buf,buf+n,cmp2);}
        if(c==3){sort(buf,buf+n,cmp3);}
        printf("Case %d:\n",cnt++);
        for(i=0;i<n;i++){
            printf("%s %s %d\n",buf[i].xue,buf[i].name,buf[i].score);
        }
    }
    return 0;
}
