#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,a[100],b[100];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int i,j;
    for(i=0;i<n-1&&b[i+1]>=b[i];i++);//找到相同元素的起点
    for(j=i+1;j<n&&a[j]==b[j];j++);//找到相同元素的终点
//    cout<<"j="<<j<<endl;
    if(j==n) {cout<<"Insertion Sort"<<endl;sort(a,a+i+2);}//相同元素到终点结束，判断为插入排序
    else{
        cout<<"Merge Sort"<<endl;
        int k=1,flag=1;
        while(flag){
            flag=0;
            for(i=0;i<n;i++){ //验证是否到了题目所给的中间步骤
                if(a[i]!=b[i]){flag=1;break;}
            }
            k=k*2; //归并排序单元长单
//            cout<<"k="<<k<<endl;
            for(i=0;i+k<=n-n%k;i+=k) //对前面的单元归并排序
                sort(a+i,a+i+k);
//            for(i=0;i<n;i++) cout<<a[i]<<' ';
            sort(a+i,a+n); //注意此处！后面不够单元长度的也要排序！如3 9 0 5 1 7 3 ，k=4时后面仍要排序
        }
    }
    cout<<a[0];
    for(i=1;i<n;i++) cout<<' '<<a[i];
    return 0;
}
