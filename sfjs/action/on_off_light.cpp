#include<iostream>
#include<cstring>
using namespace std;

//��ȡ�ַ�c�ĵ�iλ�Ķ�������ֵ��i��0��ʼ
int GetBit(char c, int i){
    return ( c >> i ) & 1;
}

//����c�ĵ�iλֵΪv
void SetBit(char &c, int i, int v){
    if(v)
        c = c | (1<<i);
    else
        c = c & ~(1<<i);
}

//��c�ĵ�iλ����ȡ��
void Flip(char &c, int i){
    c = c ^ (1<<i);
}

//�����t�β��ԵĽ��
void Output(int t, char result[]){
    cout<<"PUZZLE #"<<t<<endl;
    for(int i=0;i<5;i++){
        for(int j=0;j<6;j++){
            cout<<GetBit(result[i],j);
            if(j==5)
                cout<<'\n';
            else
                cout<<' ';
        }
    }
}

int main(){
    char oriLights[5];          //����ƾ���һ��bit��ʾһյ��
    char lights[5];             //��ͣ�仯�ĵƾ���
    char result[5];             //������ؾ���
    char switchs;               //ĳһ�еĿ���״̬
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        memset(oriLights,0,sizeof(oriLights));
        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++){
                int s;
                cin>>s;
                SetBit(oriLights[i],j,s);           //��������Ƶ�״̬
            }
        }
        for(int n=0;n<64;n++){                      //�������еƵ�64��״̬
            memcpy(lights,oriLights,sizeof(oriLights));
            switchs=n;                              //��i�еĿ���״̬
            for(int i=0;i<5;i++){
                result[i]=switchs;
                for(int j=0;j<6;j++){
                    if(GetBit(switchs,j)){          //����switchs�޸ı���
                        if(j>0) Flip(lights[i],j-1);//�޸����
                        Flip(lights[i],j);          //�޸ĵ�ǰλ��
                        if(j<5) Flip(lights[i],j+1);//�޸��ҵ�
                    }
                }
                if(i<4)
                    lights[i+1] ^= switchs;         //��һ����Ϊ���еĿ��ض��ı䡣����ϸ���
                switchs=lights[i];                  //Ϊ��ʹ���еĵ�ȫ��Ϊ0����һ�еĸı����ݾ��Ǳ��С���ϸ���
            }
            if(lights[4]==0){                       //���һ��ȫ��Ϊ0���������⡣
                Output(t,result);
                break;
            }
        }
    }
    return 0;
}
