#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
using namespace std;

/*二叉树链式存储结构*/
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

/*先序创建二叉树*/
int CreateBiTree(BiTree &T){
    char data;
    scanf("%c",&data);
    if(data=='#'){        //'#'号表示空树
        T=NULL;
    }
    else{
        T=(BiTree)malloc(sizeof(BiTNode));  //T=(BiTNode*)malloc(sizeof(BiTNode)); 也可以
        T->data=data;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return 0;
}

/*访问结点*/
void Visit(BiTree T){
    if(T) printf("%c ",T->data);
}

/*递归先序遍历*/
void PreOrder(BiTree T){
    if(T!=NULL){
        Visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

/*递归中序遍历*/
void InOrder(BiTree T){
    if(T!=NULL){
        InOrder(T->lchild);
        Visit(T);
        InOrder(T->rchild);
    }
}

/*递归后序遍历*/
void PostOrder(BiTree T){
    if(T!=NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        Visit(T);
    }
}

/*非递归先序遍历*/
void PreOrder2(BiTree T){
    stack<BiTree> s;            //申请树节点指针类型栈
    BiTree p = T;               //p是遍历指针
    while(p || !s.empty()){     //p不空或栈不空时循环
        if(p != NULL){
            Visit(p);           //访问节点
            s.push(p);          //根指针进栈
            p = p->lchild;      //遍历左子树
        }
        else{                   //根指针退栈，遍历右子树
            p = s.top();
            s.pop();
            p = p->rchild;
        }
    }

}

/*非递归中序遍历*/
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

/*非递归后续遍历*/
void PostOrder2(BiTree T){
    stack<BiTree> s;
    BiTree p = T, r = NULL;
    while(p || !s.empty()){
        if(p != NULL){               //一直往左走
            s.push(p);
            p = p->lchild;
        }
        else{                        //向右
            p = s.top();             //取栈顶节点
            if(p->rchild && p->rchild!=r){ //如果右子树存在，且未被访问过
                p = p->rchild;       //转向右
                s.push(p);
                p = p->lchild;       //再往左走
            }
            else{                    //否则，弹出节点并访问
                s.pop();
                Visit(p);
                r = p;               //记录最近访问过的节点
                p = NULL;            //节点访问完后，重置p指针
            }
        }
    }
}

/*非递归层次遍历*/
void LevelOrder(BiTree T){
    queue<BiTree> Q;
    BiTree p = T;              //遍历指针
    Q.push(p);                 //根结点入队
    while(!Q.empty()){         //队列非空则循环
        p = Q.front();         //取队头元素
        Q.pop();
        Visit(p);
        if(p->lchild != NULL)  //左子树非空，则左子树入队列
            Q.push(p->lchild);
        if(p->rchild != NULL)  //右子树非空，则右子树入队列
            Q.push(p->rchild);
    }
}

/*递归求二叉树高度*/
int Btdeep(BiTree T){
    if(T == NULL)
        return 0;
    int ldeep = Btdeep(T->lchild);
    int rdeep = Btdeep(T->rchild);
    return max(ldeep,rdeep)+1;
}

/*非递归求二叉树高度*/
const int maxsize=100;
int Btdeep2(BiTree T){
    if(T == NULL)               //空树，高度为0
        return 0;
    int front=-1,rear=-1;       //队头下标，队尾下标
    int last=0,level=0;         //last指向下一层第一个节点位置，level是层数
    BiTree Q[maxsize];          //用数组Q模拟队列，元素是二叉树结点指针
    Q[++rear]=T;                //将根结点入队
    while(front<rear){          //队不空则循环
        BiTree p = Q[++front];  //队列元素出队，即正在访问的结点
        if(p->lchild)
            Q[++rear] = p->lchild;
        if(p->rchild)
            Q[++rear] = p->rchild;
        if(front==last){        //处理该层的最右结点
            level++;            //层数加一
            last=rear;          //last指向下层
        }
    }
    return level;
}

/*根据先序遍历和中序遍历构造二叉树*/
BiTree PreInCreate(char A[], char B[],int L1,int H1,int L2,int H2){
//L1,H1为先序的第一和最后一个结点下标，L2,H2为中序的第一和最后一个结点下标
//初始调用时，L1=L2=1,H1=H2=n
    BiTree root = (BiTree)malloc(sizeof(BiTNode));
    root->data = A[L1];                 //建立根节点并赋值
    int i;
    for(i=L2;B[i]!=root->data;i++);     //找到根结点在中序序列中的位置
    int llen=i-L2;                      //左子树的长度
    int rlen=H2-i;                      //右子树的长度
    if(llen)                            //递归建立左子树
        root->lchild=PreInCreate(A,B,L1+1,L1+llen,L2,L2+llen-1);
    else                                //左子树为空
        root->lchild=NULL;
    if(rlen)                            //递归建立右子树
        root->rchild=PreInCreate(A,B,H1-rlen+1,H1,H2-rlen+1,H2);
    else                                //右子树为空
        root->rchild=NULL;
    return root;                        //返回根结点指针
}

/*判断二叉树是否为完全二叉树*/
bool IsComplete(BiTree T){
    queue<BiTree> Q;
    if(T==NULL)             //空树是满二叉树，也是完全二叉树
        return true;
    Q.push(T);
    while(!Q.empty()){      //队列非空循环
        BiTree p=Q.front();
        Q.pop();
        if(p){              //结点非空，将其做右子树入队列
            Q.push(p->lchild);
            Q.push(p->rchild);
        }
        else{               //结点为空，检查其后是否有非空结点
            while(!Q.empty()){
                p=Q.front();
                Q.pop();
                if(p)       //结点非空，则二叉树不是完全二叉树
                    return false;
            }
        }
    }
    return true;
}

/*判断两棵树是否相同*/
bool IsEqual(BiTree T1,BiTree T2){
    if(T1==NULL && T2==NULL)            //两数都为空就相等
        return true;
    if(T1 && T2 && T1->data==T2->data){ //某一棵树为空，或者两结点值不相等就不用再判断了
        if(IsEqual(T1->lchild,T2->rchild) && IsEqual(T2->lchild,T2->rchild))
            return true;
    }
    return false;
}

/*统计二叉树结点个数*/
int CountNode(BiTree T){
    if(T==NULL)
        return 0;
    return CountNode(T->lchild)+CountNode(T->rchild)+1;
}

int main(){
    BiTree T;
    CreateBiTree(T);

    printf("————————————————————\n");
    printf("递归先序遍历：");
    PreOrder(T);

    printf("\n递归中序遍历：");
    InOrder(T);

    printf("\n递归后序遍历：");
    PostOrder(T);

    printf("\n————————————————————");
    printf("\n非递归先序遍历：");
    PreOrder2(T);

    printf("\n非递归中序遍历：");
    InOrder2(T);

    printf("\n非递归后序遍历：");
    PostOrder2(T);

    printf("\n————————————————————");
    printf("\n非递归层次遍历：");
    LevelOrder(T);

    printf("\n树的高度:");
    cout<<Btdeep(T)<<endl;
    cout<<Btdeep2(T)<<endl;
    return 0;
}
