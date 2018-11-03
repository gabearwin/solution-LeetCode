#include<iostream>
#include<stack>
using namespace std;

template <class T>
class StackWithMin{
public:
    void Push(const T data){                //进栈函数
        _num.push(data);
        if(_min.empty()||data<=_min.top())  //辅助栈为空，或者有更小的值，将其存入辅助栈。注意是 <=
            _min.push(data);
    }
    void Pop(){
        if(_num.top()==_min.top())          //数据栈当前取出的元素是栈中最小的，则辅助栈也要弹出此元素
            _min.pop();
        _num.pop();
    }
    T Min(){                                //取当前最小元素
        if(!_min.empty())
            return _min.top();
    }
private:
    stack<T> _num;                          //数据栈
    stack<T> _min;                          //辅助栈
};

int main(){
    StackWithMin<int> s;
    s.Push(4);
    s.Push(3);
    s.Push(5);
    s.Push(2);
    cout<<s.Min()<<endl;
    s.Pop();
    cout<<s.Min()<<endl;
    return 0;
}
