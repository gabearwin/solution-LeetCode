#include<iostream>
#include<cstdio>
#include<stdlib.h> //atof()
#include<cstring>
using namespace std;

int main(){
    int n;
    cin>>n;
    char s[100],ss[100];
    int cnt_legal=0;
    double sum_legal=0,s_double=0;
    for(int i=0;i<n;i++){
        cin>>s;
        double s_double=atof(s); //此行与下行二选一均可
        //sscanf(s,"%lf",&s_double); //注意用法
        sprintf(ss,"%.2lf",s_double); //注意小技巧，只留两位小数，然后两字符串比较
        int flag=0;
        for(int j=0;j<strlen(s);j++){ //此处过滤非数、精度过高的数
            if(s[j]!=ss[j]) flag=1;
        }
        if(s_double<-1000||s_double>1000||flag){
            printf("ERROR: %s is not a legal number\n",s);
        }
        else {
            sum_legal+=s_double;
            cnt_legal++;
        }
    }
    if(cnt_legal==0) cout<<"The average of 0 numbers is Undefined"<<endl;
    else if(cnt_legal==1) printf("The average of 1 number is %.2f\n",sum_legal);
    else printf("The average of %d numbers is %.2f\n",cnt_legal,sum_legal/cnt_legal);
    return 0;
}
