#include<iostream>
#include<string>//为了string类
#include<sstream>//为了stringstream
using namespace std;
int main(){
    string line;
    char s[100][100];
    while(getline(cin,line)){//注意getline的用法，读取一行，不用指定大小
        int flag=0,i=0;
        stringstream ss(line);//将读取的string类型转换成流
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
