#include <iostream>
using namespace std;

const int MaxVal = 9999.9999;
const int n = 5;
//���������ڵ��������ĸ���
float p[n + 1] = {0.00,0.15,0.10,0.05,0.10,0.20};
float q[n + 1] = {0.05,0.10,0.05,0.05,0.05,0.10};

int root[n + 1][n + 1];//��¼���ڵ�
float w[n + 2][n + 1];//���������ܺ�
float e[n + 2][n + 1];//������������

void optimalBST(float *p,float *q,int n)
{
    //��ʼ��ֻ���������������
    for (int i = 1;i <= n + 1;++i)
    {
        w[i][i - 1] = q[i - 1];
        e[i][i - 1] = q[i - 1];
    }

    //���µ��ϣ��������𲽼���
    for (int len = 1;len <= n;++len)
    {
        for (int i = 1;i <= n - len + 1;++i)
        {
            int j = i + len - 1;
            e[i][j] = MaxVal;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            //��ȡ��С���۵������ĸ�
            for (int r = i;r <= j;++r)
            {
                float temp = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (temp < e[i][j])
                {
                    e[i][j] = temp;
                    root[i][j] = r;
                }
            }
        }
    }
}

//������Ŷ�����������������ĸ�
void printRoot()
{
    cout << "�������ĸ���" << endl;
    for (int i = 1;i <= n;++i)
    {
        for (int j = 1;j <= n;++j)
        {
            cout << root[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

//��ӡ���Ŷ���������Ľṹ
//��ӡ��[i,j]���������Ǹ�r����������������
void printOptimalBST(int i,int j,int r)
{
    int rootChild = root[i][j];//�������ڵ�
    if (rootChild == root[1][n])
    {
        //����������ĸ�
        cout << "k" << rootChild << "�Ǹ�" << endl;
        printOptimalBST(i,rootChild - 1,rootChild);
        printOptimalBST(rootChild + 1,j,rootChild);
        return;
    }

    if (j < i - 1)
        return;
    else if (j == i - 1)//���������
    {
        if (j < r)
            cout << "d" << j << "��" << "k" << r << "������" << endl;
        else
            cout << "d" << j << "��" << "k" << r << "���Һ���" << endl;
        return;
    }
    else//�����ڲ����
    {
        if (rootChild < r)
            cout << "k" << rootChild << "��" << "k" << r << "������" << endl;
        else
            cout << "k" << rootChild << "��" << "k" << r << "���Һ���" << endl;
    }

    printOptimalBST(i,rootChild - 1,rootChild);
    printOptimalBST(rootChild + 1,j,rootChild);
}

int main()
{
    optimalBST(p,q,n);
    printRoot();
    cout << "���Ŷ������ṹ��" << endl;
    printOptimalBST(1,n,-1);
}
