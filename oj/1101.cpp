#include<stdio.h>
#include<stack>
using namespace std;
int main(){
    int a;
    while(scanf("%d",&a)!=EOF){
        stack<int> s;
        s.push(a);
        char b;
        while(scanf("%c",&b)!=EOF){
            //if(b!='+'||b!='-'||b!='*'||b!='/') break;
            if(b=='\n') break;
            scanf("%d",&a);
            if(b=='+') s.push(a);
            else if(b=='-'){s.push(-1*a);}
            else if(b=='*'){
                int tmp=s.top();
                s.pop();
                s.push(a*tmp);
            }
            else if(b=='/'){
                int tmp=s.top();
                s.pop();
                s.push(tmp/a);
            }
        }
        int ans=0;
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        printf("%d\n",ans);
    }
    return 0;
}
