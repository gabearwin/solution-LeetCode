#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1010;
int num[maxn], maxLen[maxn];
int main(){
    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> num[i];
        maxLen[i] = 1;                                      //��ʼ����num[i]Ϊ��β������������г���Ϊ1
    }
    for(int i=2; i<=N; i++){                                //�ӵڶ�������ʼ������num[i]Ϊ�յ������������еĳ���
        for(int j=1; j<i; j++)
            if(num[j] < num[i])                             //�鿴��num[j]Ϊ�յ������������г��ȣ�������maxLen[i]��ֵ
                maxLen[i] = max(maxLen[i], maxLen[j]+1);
    }
    cout << *max_element(maxLen+1,maxLen+N+1) << endl;
    return 0;
}
