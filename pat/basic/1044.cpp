#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<sstream>
#include<cstring>
using namespace std;
char word1[][5]={"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char word2[][5]={"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
int main(){
    int n;
    cin>>n;
    getchar();
    string line;
    while(n--){
        getline(cin,line);
        stringstream ss(line);
        if(isdigit(line[0])){
            int num=0;
            ss>>num;
            if(num>=0&&num<=12){
                cout<<word1[num];
            }else if(num%13==0){
                cout<<word2[num/13-1];
            }else{
                int a=num/13,b=num%13;
                cout<<word2[a-1]<<' ';
                cout<<word1[b];
            }
        }else{
            if(line.length()>5){
                char s1[5],s2[5];
                ss>>s1>>s2;
                int sum=0;
                for(int i=0;i<12;i++){
                    if(strcmp(s1,word2[i])==0){
                        sum+=(i+1)*13;break;
                    }
                }
                for(int i=0;i<13;i++){
                    if(strcmp(s2,word1[i])==0){
                        sum+=i;break;
                    }
                }
                cout<<sum;
            }else{
                char s3[5];
                ss>>s3;
                int sum=0,flag=0;
                for(int i=0;i<13;i++){
                    if(strcmp(s3,word1[i])==0){
                        sum=i;flag=1;break;
                    }
                }
                if(flag==0){
                    for(int i=0;i<12;i++){
                        if(strcmp(s3,word2[i])==0){
                            sum=(i+1)*13;break;
                        }
                    }
                }
                cout<<sum;
            }
        }
        cout<<endl;
    }
    return 0;
}
