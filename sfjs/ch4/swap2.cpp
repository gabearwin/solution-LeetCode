#include<iostream>
#include<string>//Ϊ��string��
#include<sstream>//Ϊ��stringstream
using namespace std;
int main(){
    string line;
    char s[100][100];
    while(getline(cin,line)){//ע��getline���÷�����ȡһ�У�����ָ����С
        int flag=0,i=0;
        stringstream ss(line);//����ȡ��string����ת������
        while(ss>>s[i]){
            i++;
        }
        for(int j=i-1;j>=0;j--){
            if(flag++) cout<<' ';
            cout<<s[j];
        }
        cout<<endl;
    }
}
