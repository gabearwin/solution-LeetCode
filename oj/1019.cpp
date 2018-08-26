#include<stdio.h>
#include<stack>
using namespace std;
stack<double> s;
int main(){
    int a;
    char b,c;
    while(scanf("%d%c",&a,&b)){
        if(a==0&&b!=' ') break;
        s.push(a);
        while(scanf("%c %d%c",&c,&a,&b)!=EOF){
            if(c=='+') s.push(a);
            if(c=='-') s.push(-1.0*a);
            if(c=='*') {
                double tmp=a*s.top();
                s.pop();
                s.push(tmp);
            }
            if(c=='/'){
                double tmp=s.top()/a;
                s.pop();
                s.push(tmp);
            }
            if(b!=' ') break;
        }
        double ans=0;
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
