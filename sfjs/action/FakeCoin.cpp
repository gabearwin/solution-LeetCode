#include<iostream>
#include<cstring>
using namespace std;

char Left[3][10];                       //��ƽ���Ӳ��
char Right[3][10];                      //��ƽ�ұ�Ӳ��
char Result[3][10];                     //ÿ�ν��

bool IsFake(char c, bool light){        //lightΪtrueʱ���ٱ�����ģ�lightΪfalseʱ���ٱ����ص�
    for(int i=0;i<3;i++){               //���ν����һ��֤
        char *pLeft,*pRight;            //ָ����ƽ���ߵ��ַ���
        if(light){
            pLeft=Left[i];
            pRight=Right[i];
        }
        else{
            pLeft=Right[i];
            pRight=Left[i];
        }
        switch(Result[i][0]){                           //Ϊ������⣬����ע��ֱ����cΪ�ٵ���������͡�cΪ�ص������������if...else������ͬ����⡣
            case 'u':
                if(strchr(pRight,c)==NULL)              //��ƽ�ұ߱�����ᣬ�ٱҲ����ұ߿϶��ʹ���
                    return false;
                break;
            case 'd':
                if(strchr(pLeft,c)==NULL)               //��ƽ�ұ߱�����أ��ٱҲ�����߿϶�����
                    return false;
                break;
            case 'e':
                if(strchr(pLeft,c)||strchr(pRight,c))   //��ƽƽ��ʱ���ٱҳ�������߻����ұ߶�����
                    return false;
                break;
        }
    }
    return true;                        //���ν����ͨ�����飬����true

}
int main(){
    int T;
    cin>>T;
    while(T--){
        for(int i=0;i<3;i++)
            cin>>Left[i]>>Right[i]>>Result[i];
        for(char c='A';c<='L';c++){     //��12��Ӳ�����γ���
            if(IsFake(c,true)){         //c�ǼٱҲ��������
                cout<<c<<" is the counterfeit coin and it is light."<<endl;
                break;
            }
            else if(IsFake(c,false)){   //c�ǼٱҲ������ص�
                cout<<c<<" is the counterfeit coin and it is heavy."<<endl;
                break;
            }
        }
    }
    return 0;
}
