#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<time.h>
using namespace std;
int main(){
    int count=0,box[20],num=1,temp,cunt[20];
    memset(box,0,sizeof(box));
    memset(cunt,0,sizeof(cunt));
    while(~scanf("%d",&box[0])){
        cunt[0]=1;
        while(count++<11){
            scanf("%d",&temp);
            int flag=0;
            for(int i=0;i<num;i++){
                if(temp==box[i]) {cunt[i]++;flag=1;break;}
            }
            if(flag==0) {cunt[num]++;box[num++]=temp;}
        }
        if(num==3&&cunt[0]==4&&cunt[1]==4&&cunt[2]==4) printf("POSSIBLE\n");
        else if(num==1&&cunt[0]==12) printf("POSSIBLE\n");
        else if((num==2&&cunt[0]==4&&cunt[1]==8)||(num==2&&cunt[0]==8&&cunt[1]==4))
            printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
        count=0,num=1;
        memset(box,0,sizeof(box));
        memset(cunt,0,sizeof(cunt));
    }
    return 0;
}
