#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char a[100],b[100],c[100];
    memset(c,'0',sizeof(c));
    cin>>a>>b;
    int cnt=1;
    char sa,sb;
    for(int i=strlen(a)-1,j=strlen(b)-1;i>=0||j>=0;i--,j--,cnt++){
        if(i>=0) sa=a[i];
        else sa='0';
        if(j>=0) sb=b[j];
        else sb='0';
        if(cnt%2==1){
            int temp=(sa-'0'+sb-'0')%13;
            if(temp>=0&&temp<=9){
                c[cnt-1]=temp+'0';
            }else if(temp==10) c[cnt-1]='J';
            else if(temp==11) c[cnt-1]='Q';
            else if(temp==12) c[cnt-1]='K';
        }else{
            int temp=sb-sa;
            if(temp>=0) c[cnt-1]=temp+'0';
            else c[cnt-1]=temp+10+'0';
        }
    }
    for(int i=cnt-2;i>=0;i--) cout<<c[i];
    return 0;
}
