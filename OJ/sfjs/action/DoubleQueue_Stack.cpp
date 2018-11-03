#include<iostream>
#include<queue>
using namespace std;

template<class T>
class DoubleQueue_Stack{
public:
    void Push(T data){                  //��Ԫ��ѹ��q1
        q1.push(data);
    }
    void Pop(){                         //Ԫ�س�ջ�����ǵ������һ�������Ԫ��
        if(!q1.empty()){                //q1�ǿգ��Ͱ�q1���һ����������ʱ����Ԫ�ؽ�q2
            while(q1.size()>1){
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
        }
        else if(!q2.empty()){           //q2�ǿգ��Ͱ�q2���һ����������ʱ����Ԫ�ؽ�q1
            while(q2.size()>1){
                q1.push(q2.front());
                q2.pop();
            }
            q2.pop();
        }
    }
    T& Top(){                           //ȡջ��Ԫ�أ�����ȡ�������������һ��
        if(!q1.empty())
            return q1.back();
        if(!q2.empty())
            return q2.back();
    }
    bool Empty(){                       //q1��q2���ǿգ�ջ��Ϊ��
        if(q1.empty()&&q2.empty())
            return true;
        return false;
    }
private:
    queue<T> q1;
    queue<T> q2;
};

int main(){
    DoubleQueue_Stack<int> s;
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    s.Pop();
    s.Push(5);
    s.Push(6);
    s.Pop();
    s.Pop();
    cout<<s.Top()<<endl;
    return 0;
}
