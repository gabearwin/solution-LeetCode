#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int P, T, G1, G2, G3, GJ;
    while(scanf("%d%d%d%d%d%d",&P,&T,&G1,&G2,&G3,&GJ)!=EOF){
        if(abs(double(G1-G2))<=T) {printf("%.1lf\n",(G1+G2)/2.0);}
        else if(abs(double(G1-G3))<=T&&abs(double(G2-G3))>T||abs(double(G1-G3))>T&&abs(double(G2-G3))<=T){
            if(abs(double(G1-G3))<abs(double(G2-G3))) {printf("%.1lf\n",(G1+G3)/2.0); }
            else {printf("%.1lf\n",(G2+G3)/2.0);}
        }
        else if(abs(double(G1-G3))<=T&&abs(double(G2-G3))<=T){
            int tmp=G1;
            if(tmp<G2) tmp=G2;
            if(tmp<G3) tmp=G3;
            printf("%.1lf\n",tmp*1.0);
        }
        else {printf("%.1lf\n",GJ*1.0);}
    }
    return 0;
}
