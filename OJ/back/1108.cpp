#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;
int main(){
    int n,b,i;
    char a;
    while(scanf("%d",&n)!=EOF&&n!=0){
        stack<int> s;
        for(i=0;i<n;i++){
            cin>>a;
/*特别注意此处，如果换成scanf要消去后面的空格才行。
            可以用getchar，或者用while(getchar()!='\n')*/
/*scanf()之后，可能留下不只一个空格，你把循环体里面最后一个
getchar改为while（getchar（)!='\n'）;就可以吃掉缓冲区里面所有字符。就AC了*/
            if(a=='A') {
                if(!s.empty()) printf("%d\n",s.top());
                else printf("E\n");
            }
            else if(a=='O') {
                if(!s.empty()) s.pop();
            }
            else if(a=='P'){
                scanf("%d",&b);
                s.push(b);
            }
        }
        printf("\n");
    }
    return 0;
}
