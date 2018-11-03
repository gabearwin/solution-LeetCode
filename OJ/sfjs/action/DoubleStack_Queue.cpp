#include<iostream>
#include<stack>
using namespace std;

template <class T>
class DoubleStack_Queue{
public:
    void Push(T data){
        s1.push(data);              //ֱ��ѹ��s1
    }
    void Pop(){                     //����������ջ���Ǹ�
        if(s2.empty()){             //s2Ϊ�գ��Ͱ�s1����ѹ�뵽s2������s1���һ��
            while(s1.size()>1){
                s2.push(s1.top());
                s1.pop();
            }
            s1.pop();
        }
        else{                       //s2��Ϊ�գ�ֱ�ӵ���s2ջ��Ԫ��
            s2.pop();
        }
    }
    bool Empty(){                   //�ж��Ƿ�Ϊ�գ���s1��s2��Ϊ��ʱ����Ϊ��
        if(s1.empty()&&s2.empty())
            return true;
        return false;
    }
    T& Front(){                     //�ҵ������Ԫ�ء���Pop˼��һ����
        if(!s2.empty())
            return s2.top();
        if(!s1.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
    T& Back(){                      //�ҵ���������Ԫ��
        if(!s1.empty())             //s1�ǿգ�ֱ��ȡs1ջ��Ԫ��
            return s1.top();
        if(!s2.empty()){            //s1Ϊ�գ���s2�е�Ԫ�ص�װ��s1�У�Ȼ��ȡs1ջ��
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
            return s1.top();
        }
    }
private:
    stack<T> s1;
    stack<T> s2;
};

int main(){
    DoubleStack_Queue<int> Q;
    Q.Push(6);
    Q.Push(7);
    Q.Push(3);
    Q.Push(8);
    Q.Pop();
    Q.Push(9);
    Q.Push(10);
    cout<<Q.Front()<<' '<<Q.Back()<<endl;
    return 0;
}
