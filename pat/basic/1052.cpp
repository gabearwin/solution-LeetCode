#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main(){
    vector<vector <string> > str;
    for(int i=0;i<3;i++){
        string s;
        getline(cin,s);
        vector<string> temp;
        for(int j=0;j<s.length();j++){
            if(s[j]=='['){
                for(int k=j;k<s.length();k++){
                    if(s[k]==']') {
                        temp.push_back(s.substr(j+1,k-j-1));
                        break;
                    }
                }
            }
        }
        str.push_back(temp);
    }
    int n,a,b,c,d,e;
    cin>>n;
    while(n--){
        cin>>a>>b>>c>>d>>e;
        if(a<1||b<1||c<1||d<1||e<1||a>str[0].size()||b>str[1].size()||c>str[2].size())
            cout<<"Are you kidding me? @\\/@"<<endl;
        else cout<<str[0][a-1]<<'('<<str[1][b-1]<<str[2][c-1]<<str[1][d-1]<<')'<<str[0][e-1]<<endl;
    }
    return 0;
}
