#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int D,I;
    while(cin>>D>>I){
        int k=1; //k是最后一个小球所走的序号
        for(int i=0;i<D-1;i++){
            if(I%2){
                k=2*k; //奇数往左走
                I=(I+1)/2; //是往左走的第(I+1)/2个
            }else{
                k=2*k+1; //偶数往右走
                I=I/2; //是往右走的第I/2个
            }
        }
        cout<<k<<endl;
    }
    return 0;
}
