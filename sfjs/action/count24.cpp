#include<iostream>
#include<cmath>
using namespace std;
double a[5];
#define EPS 1e-6                    //10^(-6)����������С�����������Ϊ��0(���Ը�С����-8�η�)
bool isZero(double x){              //�жϸ������Ƿ�Ϊ0
    return fabs(x) <= EPS;
}
bool count24(double a[], int n){    //����a��n�����ܷ����24
    if(n == 1){                     //�����н���һ��Ԫ��
        if(isZero(a[0]-24))
            return true;
        else
            return false;
    }
    double b[5];
    for(int i=0;i<n-1;i++){         //ö�������������
        for(int j=i+1;j<n;j++){
            int m=0;
            for(int k=0;k<n;k++){   //��ʣ�µ�n-2������ŵ�����b��
                if(k!=i && k!=j)
                    b[m++]=a[k];
            }
            b[m]=a[i]+a[j];         //Ԫ��b[m]��a[i]��a[j]���
            if(count24(b,m+1))
                return true;
            b[m]=a[i]-a[j];         //Ԫ��b[m]��a[i]��a[j]���
            if(count24(b,m+1))
                return true;
            b[m]=a[j]-a[i];
            if(count24(b,m+1))
                return true;
            b[m]=a[i]*a[j];         //Ԫ��b[m]��a[i]��a[j]���
            if(count24(b,m+1))
                return true;
            if(!isZero(a[j])){      //Ԫ��b[m]��a[i]��a[j]���
                b[m]=a[i]/a[j];
                if(count24(b,m+1))
                return true;
            }
            if(!isZero(a[i])){
                b[m]=a[j]/a[i];
                if(count24(b,m+1))
                return true;
            }
        }
    }
    return false;
}
int main(){
    while(true){
        for(int i=0;i<4;i++)        //����4��Ԫ��
            cin>>a[i];
        if(isZero(a[0])&&isZero(a[1])&&isZero(a[2])&&isZero(a[3]))
            break;
        if(count24(a,4))            //�������24
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
