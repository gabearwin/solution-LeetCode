#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
typedef struct boxs{
    int x;
    int y;
}mybox;
void myswap(int *a,int *b){int c;c=*a;*a=*b;*b=c; }
int cmp(mybox a,mybox b){
    if(a.x!=b.x) return a.x<b.x;
    else return a.y<b.y;
}
int main(){
    int count=0;
    mybox box[6];
    while(~scanf("%d%d",&box[0].x,&box[0].y)){
        if(box[0].x>box[0].y) myswap(&box[0].x,&box[0].y);
        while(count++<5){
            scanf("%d%d",&box[count].x,&box[count].y);
            if(box[count].x>box[count].y) myswap(&box[count].x,&box[count].y);
        }
        sort(box,box+6,cmp);
        /*for(int i=0;i<6;i++){
            printf("%d %d\n",box[i].x,box[i].y);
        }*/
        int flag=0;
        if(box[0].x==box[1].x&&box[1].x==box[2].x&&box[2].x==box[3].x ){
            if(box[0].y==box[1].y&&box[1].y==box[4].x&&box[4].x==box[5].x){
                if(box[2].y==box[3].y&&box[3].y==box[4].y&&box[4].y==box[5].y)
                    flag=1;
            }
        }
        if(flag==1) printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
        count=0;
    }
    return 0;
}
