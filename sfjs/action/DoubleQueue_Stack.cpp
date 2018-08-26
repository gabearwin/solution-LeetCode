#include<iostream>
#include<queue>
using namespace std;

template<class T>
class DoubleQueue_Stack{
public:
    void Push(T data){                  //将元素压入q1
        q1.push(data);
    }
    void Pop(){                         //元素出栈，就是弹出最后一个进入的元素
        if(!q1.empty()){                //q1非空，就把q1最后一个弹出，这时其他元素进q2
            while(q1.size()>1){
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
        }
        else if(!q2.empty()){           //q2非空，就把q2最后一个弹出，这时其他元素进q1
            while(q2.size()>1){
                q1.push(q2.front());
                q2.pop();
            }
            q2.pop();
        }
    }
    T& Top(){                           //取栈顶元素，就是取队列最后进入的那一个
        if(!q1.empty())
            return q1.back();
        if(!q2.empty())
            return q2.back();
    }
    bool Empty(){                       //q1和q2都非空，栈才为空
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
