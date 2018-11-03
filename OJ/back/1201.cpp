#include<stdio.h>
struct Node{
    Node *lchild;
    Node *rchild;
    int c;
}Tree[150];
int loc;
Node *creat(){
    Tree[loc].lchild=Tree[loc].rchild=NULL;
    return &Tree[loc++];
}
void preOrder(Node *T){
    printf("%d ",T->c);
    if(T->lchild!=NULL) preOrder(T->lchild);
    if(T->rchild!=NULL) preOrder(T->rchild);
}
void inOrder(Node *T){
    if(T->lchild!=NULL) inOrder(T->lchild);
    printf("%d ",T->c);
    if(T->rchild!=NULL) inOrder(T->rchild);
}
void postOrder(Node *T){
    if(T->lchild!=NULL) postOrder(T->lchild);
    if(T->rchild!=NULL) postOrder(T->rchild);
    printf("%d ",T->c);
}
Node *ins(Node *T,int x){
    if(T==NULL){
        T=creat();
        T->c=x;
        return T;
    }
    else if(T->c<x) T->rchild=ins(T->rchild,x);
    else if(T->c>x) T->lchild=ins(T->lchild,x);
    return T;
}
int main(){
    int n,a;
    while(scanf("%d",&n)!=EOF){
        Node *T=NULL;
        loc=0;
        while(n--){
            scanf("%d",&a);
            T=ins(T,a);
        }
        preOrder(T);
        printf("\n");
        inOrder(T);
        printf("\n");
        postOrder(T);
        printf("\n");
    }
    return 0;
}
