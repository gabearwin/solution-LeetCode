#include<iostream>
#include<stack>
using namespace std;

template <class T>
class DoubleStack_Queue{
public:
    void Push(T data){
        s1.push(data);              //直接压入s1
    }
    void Pop(){                     //弹出最早入栈的那个
        if(s2.empty()){             //s2为空，就把s1倒着压入到s2，弹出s1最后一个
            while(s1.size()>1){
                s2.push(s1.top());
                s1.pop();
            }
            s1.pop();
        }
        else{                       //s2不为空，直接弹出s2栈顶元素
            s2.pop();
        }
    }
    bool Empty(){                   //判断是否为空：当s1和s2都为空时队列为空
        if(s1.empty()&&s2.empty())
            return true;
        return false;
    }
    T& Front(){                     //找到最早的元素。和Pop思想一样。
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
    T& Back(){                      //找到最后进来的元素
        if(!s1.empty())             //s1非空，直接取s1栈顶元素
            return s1.top();
        if(!s2.empty()){            //s1为空，将s2中的元素倒装到s1中，然后取s1栈顶
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
