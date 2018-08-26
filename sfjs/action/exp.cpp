#include<iostream>
#include<cstdio>                        //printf()
#include<cstdlib>                       //atof()
using namespace std;

double exp(){                           //读入一个逆波兰表达式，并计算其值
    char s[20];
    cin >> s;                           //读入一个表达式
    switch(s[0]){
        case '+': return exp() + exp(); //当前是+号，递归进行加运算
        case '-': return exp() - exp();
        case '*': return exp() * exp(); //当前是*号，递归进行乘运算
        case '/': return exp() / exp();
        default: return atof(s); break; //当前是一个数，将字符串转换成浮点数
    }
}
int main(){
    printf("%lf",exp());
    return 0;
}
