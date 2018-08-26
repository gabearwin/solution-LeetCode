#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int main(){
    if(_unlink("G:\\1.txt")==0){
        cout<<"well done"<<endl;
        exit(EXIT_SUCCESS);
    }else{
        cout<<"delete fail"<<endl;
        exit(EXIT_FAILURE);
    }
    return 0;
}
