#include<iostream>
#include<cstring>
using namespace std;

//获取字符c的第i位的二进制数值，i从0开始
int GetBit(char c, int i){
    return ( c >> i ) & 1;
}

//设置c的第i位值为v
void SetBit(char &c, int i, int v){
    if(v)
        c = c | (1<<i);
    else
        c = c & ~(1<<i);
}

//将c的第i位进行取反
void Flip(char &c, int i){
    c = c ^ (1<<i);
}

//输出第t次测试的结果
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
    char oriLights[5];          //最初灯矩阵，一个bit表示一盏灯
    char lights[5];             //不停变化的灯矩阵
    char result[5];             //结果开关矩阵
    char switchs;               //某一行的开关状态
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        memset(oriLights,0,sizeof(oriLights));
        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++){
                int s;
                cin>>s;
                SetBit(oriLights[i],j,s);           //读入最初灯的状态
            }
        }
        for(int n=0;n<64;n++){                      //遍历首行灯的64种状态
            memcpy(lights,oriLights,sizeof(oriLights));
            switchs=n;                              //第i行的开关状态
            for(int i=0;i<5;i++){
                result[i]=switchs;
                for(int j=0;j<6;j++){
                    if(GetBit(switchs,j)){          //依据switchs修改本行
                        if(j>0) Flip(lights[i],j-1);//修改左灯
                        Flip(lights[i],j);          //修改当前位置
                        if(j<5) Flip(lights[i],j+1);//修改右灯
                    }
                }
                if(i<4)
                    lights[i+1] ^= switchs;         //下一行因为本行的开关而改变。请仔细理解
                switchs=lights[i];                  //为了使本行的灯全部为0，下一行的改变依据就是本行。仔细理解
            }
            if(lights[4]==0){                       //最后一行全部为0，符合题意。
                Output(t,result);
                break;
            }
        }
    }
    return 0;
}
