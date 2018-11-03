#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
using namespace std;

/*��������ʽ�洢�ṹ*/
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

/*���򴴽�������*/
int CreateBiTree(BiTree &T){
    char data;
    scanf("%c",&data);
    if(data=='#'){        //'#'�ű�ʾ����
        T=NULL;
    }
    else{
        T=(BiTree)malloc(sizeof(BiTNode));  //T=(BiTNode*)malloc(sizeof(BiTNode)); Ҳ����
        T->data=data;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return 0;
}

/*���ʽ��*/
void Visit(BiTree T){
    if(T) printf("%c ",T->data);
}

/*�ݹ��������*/
void PreOrder(BiTree T){
    if(T!=NULL){
        Visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

/*�ݹ��������*/
void InOrder(BiTree T){
    if(T!=NULL){
        InOrder(T->lchild);
        Visit(T);
        InOrder(T->rchild);
    }
}

/*�ݹ�������*/
void PostOrder(BiTree T){
    if(T!=NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        Visit(T);
    }
}

/*�ǵݹ��������*/
void PreOrder2(BiTree T){
    stack<BiTree> s;            //�������ڵ�ָ������ջ
    BiTree p = T;               //p�Ǳ���ָ��
    while(p || !s.empty()){     //p���ջ�ջ����ʱѭ��
        if(p != NULL){
            Visit(p);           //���ʽڵ�
            s.push(p);          //��ָ���ջ
            p = p->lchild;      //����������
        }
        else{                   //��ָ����ջ������������
            p = s.top();
            s.pop();
            p = p->rchild;
        }
    }

}

/*�ǵݹ��������*/
void InOrder2(BiTree T){
    stack<BiTree> s;
    BiTree p = T;
    while(p || !s.empty()){
        if(p != NULL){
            s.push(p);
            p = p->lchild;
        }
        else{
            p = s.top();
            s.pop();
            Visit(p);
            p = p->rchild;
        }
    }
}

/*�ǵݹ��������*/
void PostOrder2(BiTree T){
    stack<BiTree> s;
    BiTree p = T, r = NULL;
    while(p || !s.empty()){
        if(p != NULL){               //һֱ������
            s.push(p);
            p = p->lchild;
        }
        else{                        //����
            p = s.top();             //ȡջ���ڵ�
            if(p->rchild && p->rchild!=r){ //������������ڣ���δ�����ʹ�
                p = p->rchild;       //ת����
                s.push(p);
                p = p->lchild;       //��������
            }
            else{                    //���򣬵����ڵ㲢����
                s.pop();
                Visit(p);
                r = p;               //��¼������ʹ��Ľڵ�
                p = NULL;            //�ڵ�����������pָ��
            }
        }
    }
}

/*�ǵݹ��α���*/
void LevelOrder(BiTree T){
    queue<BiTree> Q;
    BiTree p = T;              //����ָ��
    Q.push(p);                 //��������
    while(!Q.empty()){         //���зǿ���ѭ��
        p = Q.front();         //ȡ��ͷԪ��
        Q.pop();
        Visit(p);
        if(p->lchild != NULL)  //�������ǿգ��������������
            Q.push(p->lchild);
        if(p->rchild != NULL)  //�������ǿգ��������������
            Q.push(p->rchild);
    }
}

/*�ݹ���������߶�*/
int Btdeep(BiTree T){
    if(T == NULL)
        return 0;
    int ldeep = Btdeep(T->lchild);
    int rdeep = Btdeep(T->rchild);
    return max(ldeep,rdeep)+1;
}

/*�ǵݹ���������߶�*/
const int maxsize=100;
int Btdeep2(BiTree T){
    if(T == NULL)               //�������߶�Ϊ0
        return 0;
    int front=-1,rear=-1;       //��ͷ�±꣬��β�±�
    int last=0,level=0;         //lastָ����һ���һ���ڵ�λ�ã�level�ǲ���
    BiTree Q[maxsize];          //������Qģ����У�Ԫ���Ƕ��������ָ��
    Q[++rear]=T;                //����������
    while(front<rear){          //�Ӳ�����ѭ��
        BiTree p = Q[++front];  //����Ԫ�س��ӣ������ڷ��ʵĽ��
        if(p->lchild)
            Q[++rear] = p->lchild;
        if(p->rchild)
            Q[++rear] = p->rchild;
        if(front==last){        //����ò�����ҽ��
            level++;            //������һ
            last=rear;          //lastָ���²�
        }
    }
    return level;
}

/*�����������������������������*/
BiTree PreInCreate(char A[], char B[],int L1,int H1,int L2,int H2){
//L1,H1Ϊ����ĵ�һ�����һ������±꣬L2,H2Ϊ����ĵ�һ�����һ������±�
//��ʼ����ʱ��L1=L2=1,H1=H2=n
    BiTree root = (BiTree)malloc(sizeof(BiTNode));
    root->data = A[L1];                 //�������ڵ㲢��ֵ
    int i;
    for(i=L2;B[i]!=root->data;i++);     //�ҵ�����������������е�λ��
    int llen=i-L2;                      //�������ĳ���
    int rlen=H2-i;                      //�������ĳ���
    if(llen)                            //�ݹ齨��������
        root->lchild=PreInCreate(A,B,L1+1,L1+llen,L2,L2+llen-1);
    else                                //������Ϊ��
        root->lchild=NULL;
    if(rlen)                            //�ݹ齨��������
        root->rchild=PreInCreate(A,B,H1-rlen+1,H1,H2-rlen+1,H2);
    else                                //������Ϊ��
        root->rchild=NULL;
    return root;                        //���ظ����ָ��
}

/*�ж϶������Ƿ�Ϊ��ȫ������*/
bool IsComplete(BiTree T){
    queue<BiTree> Q;
    if(T==NULL)             //����������������Ҳ����ȫ������
        return true;
    Q.push(T);
    while(!Q.empty()){      //���зǿ�ѭ��
        BiTree p=Q.front();
        Q.pop();
        if(p){              //���ǿգ������������������
            Q.push(p->lchild);
            Q.push(p->rchild);
        }
        else{               //���Ϊ�գ��������Ƿ��зǿս��
            while(!Q.empty()){
                p=Q.front();
                Q.pop();
                if(p)       //���ǿգ��������������ȫ������
                    return false;
            }
        }
    }
    return true;
}

/*�ж��������Ƿ���ͬ*/
bool IsEqual(BiTree T1,BiTree T2){
    if(T1==NULL && T2==NULL)            //������Ϊ�վ����
        return true;
    if(T1 && T2 && T1->data==T2->data){ //ĳһ����Ϊ�գ����������ֵ����ȾͲ������ж���
        if(IsEqual(T1->lchild,T2->rchild) && IsEqual(T2->lchild,T2->rchild))
            return true;
    }
    return false;
}

/*ͳ�ƶ�����������*/
int CountNode(BiTree T){
    if(T==NULL)
        return 0;
    return CountNode(T->lchild)+CountNode(T->rchild)+1;
}

int main(){
    BiTree T;
    CreateBiTree(T);

    printf("����������������������������������������\n");
    printf("�ݹ����������");
    PreOrder(T);

    printf("\n�ݹ����������");
    InOrder(T);

    printf("\n�ݹ���������");
    PostOrder(T);

    printf("\n����������������������������������������");
    printf("\n�ǵݹ����������");
    PreOrder2(T);

    printf("\n�ǵݹ����������");
    InOrder2(T);

    printf("\n�ǵݹ���������");
    PostOrder2(T);

    printf("\n����������������������������������������");
    printf("\n�ǵݹ��α�����");
    LevelOrder(T);

    printf("\n���ĸ߶�:");
    cout<<Btdeep(T)<<endl;
    cout<<Btdeep2(T)<<endl;
    return 0;
}
