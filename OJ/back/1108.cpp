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
/*�ر�ע��˴����������scanfҪ��ȥ����Ŀո���С�
            ������getchar��������while(getchar()!='\n')*/
/*scanf()֮�󣬿������²�ֻһ���ո����ѭ�����������һ��
getchar��Ϊwhile��getchar��)!='\n'��;�Ϳ��ԳԵ����������������ַ�����AC��*/
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
