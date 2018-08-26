#include<iostream>
#include<cstdio>
#include<ctype.h> //isalpha()/isdigit()/isupper()/islower
#include<cstring>
using namespace std;

int main(){
    char day[7][5]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    char a[60],b[60],c[60],d[60];
    cin>>a>>b>>c>>d;
    int cnt=1,day_num=0,hour_num=0,minute_num=0;
    for(int i=0;i<strlen(a)&&i<strlen(b);i++){
        if(a[i]==b[i]){
            if(cnt==1&&a[i]>='A'&&a[i]<='G'){
                day_num=a[i]-'A';
                cnt++;
            }else if(cnt==2){
                if(isdigit(a[i])){
                    hour_num=a[i]-'0'; //注意此处不要忘记减去字符'0'
                    break;
                }else if(a[i]>='A'&&a[i]<='N'){
                    hour_num=a[i]-'A'+10;
                    break;
                }
            }
        }
    }
    for(int i=0;i<strlen(c)&&i<strlen(d);i++){
        if(c[i]==d[i]&&isalpha(c[i])) {minute_num=i;break;}
    }
    //cout<<day_num<<' '<<hour_num<<' '<<minute_num<<endl;
    printf("%s %02d:%02d\n",day[day_num],hour_num,minute_num);
}
