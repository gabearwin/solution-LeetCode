#include<stdio.h>
#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;
int main(){
    char z,pan[10][10];
    int num=0,i=0,j=0,x=0,y=0,flag=1,count=0;
    while(1){
        for(int i=0;i<5;i++){
            cin.getline(pan[i],10);//注意此函数的用法
            if(pan[i][0]=='Z') return 0;
            if(pan[i][4]=='\0') pan[i][4]=' ';//cin.getline()函数自动在结尾处添加结束标志'\0'
        }
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(pan[i][j]==' '){x=i,y=j;}
            }
        }
        //printf("x=%d y=%d\n",x,y);
        while(~scanf("%c",&z)){
            if(z=='A'){
                if(x>=1){pan[x][y]=pan[x-1][y];x=x-1;}
                else flag=0;
            }else if(z=='B'){
                if(x<=3){pan[x][y]=pan[x+1][y];x=x+1;}
                else flag=0;
            }else if(z=='L'){
                if(y>=1){pan[x][y]=pan[x][y-1];y=y-1;}
                else flag=0;
            }else if(z=='R'){
                if(y<=3){pan[x][y]=pan[x][y+1];y=y+1;}
                else flag=0;
            }else if(z=='0') break;
        }
        getchar();//注意上面'ABLR0'之后的回车，消去回车
        if(count++) printf("\n");
        printf("Puzzle #%d:\n",count);
        if(flag){
            pan[x][y]=' ';
            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    if(j==4) printf("%c\n",pan[i][j]);
                    else printf("%c ",pan[i][j]);
                }
            }
        }else{
            printf("This puzzle has no final configuration.\n");
            /*for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    if(j==4) printf("%c\n",pan[i][j]);
                    else printf("%c ",pan[i][j]);
                }
            }*/
        }
        num=0,x=0,y=0,flag=1;
        memset(pan,' ',sizeof(pan));
    }
    return 0;
}
