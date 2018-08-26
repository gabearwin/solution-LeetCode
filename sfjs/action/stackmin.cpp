#include<iostream>
#include<stack>
using namespace std;

template <class T>
class StackWithMin{
public:
    void Push(const T data){                //��ջ����
        _num.push(data);
        if(_min.empty()||data<=_min.top())  //����ջΪ�գ������и�С��ֵ��������븨��ջ��ע���� <=
            _min.push(data);
    }
    void Pop(){
        if(_num.top()==_min.top())          //����ջ��ǰȡ����Ԫ����ջ����С�ģ�����ջҲҪ������Ԫ��
            _min.pop();
        _num.pop();
    }
    T Min(){                                //ȡ��ǰ��СԪ��
        if(!_min.empty())
            return _min.top();
    }
private:
    stack<T> _num;                          //����ջ
    stack<T> _min;                          //����ջ
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
