#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct stu{
    char name[100];
    char no[100];
    int score;
    bool operator < (const stu &b) const{
        if(score!=b.score) return score<b.score;
        else return false;
    }
}s[100];
bool cmp(struct stu a, struct stu b){
    return a.score<b.score;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%s%s%d",s[i].name,s[i].no,&s[i].score);
        }
        sort(s,s+n,cmp);
        printf("%s %s\n",s[n-1].name,s[n-1].no);
        printf("%s %s\n",s[0].name,s[0].no);
    }
    return 0;
}
