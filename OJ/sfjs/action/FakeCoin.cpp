#include<iostream>
#include<cstring>
using namespace std;

char Left[3][10];                       //天平左边硬币
char Right[3][10];                      //天平右边硬币
char Result[3][10];                     //每次结果

bool IsFake(char c, bool light){        //light为true时，假币是轻的；light为false时，假币是重的
    for(int i=0;i<3;i++){               //三次结果逐一验证
        char *pLeft,*pRight;            //指向天平两边的字符串
        if(light){
            pLeft=Left[i];
            pRight=Right[i];
        }
        else{
            pLeft=Right[i];
            pRight=Left[i];
        }
        switch(Result[i][0]){                           //为便于理解，下面注释直接以c为假的轻的来解释。c为重的情况，在上面if...else操作后同样理解。
            case 'u':
                if(strchr(pRight,c)==NULL)              //天平右边比左边轻，假币不在右边肯定就错了
                    return false;
                break;
            case 'd':
                if(strchr(pLeft,c)==NULL)               //天平右边比左边重，假币不在左边肯定错了
                    return false;
                break;
            case 'e':
                if(strchr(pLeft,c)||strchr(pRight,c))   //天平平衡时，假币出现在左边或者右边都不行
                    return false;
                break;
        }
    }
    return true;                        //三次结果都通过检验，返回true

}
int main(){
    int T;
    cin>>T;
    while(T--){
        for(int i=0;i<3;i++)
            cin>>Left[i]>>Right[i]>>Result[i];
        for(char c='A';c<='L';c++){     //这12个硬币依次尝试
            if(IsFake(c,true)){         //c是假币并且是轻的
                cout<<c<<" is the counterfeit coin and it is light."<<endl;
                break;
            }
            else if(IsFake(c,false)){   //c是假币并且是重的
                cout<<c<<" is the counterfeit coin and it is heavy."<<endl;
                break;
            }
        }
    }
    return 0;
}
