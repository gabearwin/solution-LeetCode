#include<iostream>
#include<cstdio>                        //printf()
#include<cstdlib>                       //atof()
using namespace std;

double exp(){                           //����һ���沨�����ʽ����������ֵ
    char s[20];
    cin >> s;                           //����һ�����ʽ
    switch(s[0]){
        case '+': return exp() + exp(); //��ǰ��+�ţ��ݹ���м�����
        case '-': return exp() - exp();
        case '*': return exp() * exp(); //��ǰ��*�ţ��ݹ���г�����
        case '/': return exp() / exp();
        default: return atof(s); break; //��ǰ��һ���������ַ���ת���ɸ�����
    }
}
int main(){
    printf("%lf",exp());
    return 0;
}
