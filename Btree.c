#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
typedef struct QNode
{
    void *data;
    struct QNode *next;
} QNode;

typedef struct Queue
{
    struct QNode *front;
    struct QNode *rear;
} Queue;
typedef struct SNode{
    void *data;
    struct SNode *next;
}SNode;

SNode* createNewSNode(void *data){
 SNode* newSNode=(SNode*)malloc(sizeof(SNode));
 newSNode->next=NULL;
 newSNode->data=data;
 return newSNode;
}
void push(SNode **top,void* data)
{
 SNode *newNode=createNewSNode(data);
 if(*top==NULL){
     *top=newNode;
     return;
 }
 //newNode=createNewSNode(data);
 newNode->next=*top;
 *top=newNode;
}
void* pop(SNode **top)
{
if(*top==NULL){
   // printf("Stack is EMPTY");
    return NULL ;
}
SNode *temp=*top;
void *data1=temp->data;
*top=temp->next;
//free(temp);
return data1;
}
QNode *getQNode(void *data)
{
    QNode *q = (QNode *)malloc(sizeof(QNode));
    q->data = data;
    q->next = NULL;
    return q;
}
void enQueue(Queue *q, void *data)
{
    QNode *newNode = getQNode(data);
    if (q->front == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}
void *dQueue(Queue *q)
{
    QNode *temp;
    void *d;
    if (q->front == NULL)
    {
        return NULL;
    }
    temp = q->front;
    d = q->front->data;
    q->front = q->front->next;
    free(temp);
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    return d;
}

int isEmpty(Queue *q)
{
    return q->front == NULL;
}

typedef struct TNode
{
    struct TNode *left;
    void* data;
    struct TNode *right;
} TNode;

TNode *newTNode(void* data)
{
    TNode *newNode = (TNode *)malloc(sizeof(TNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void insertBTree(TNode **root, void* data)
{
    Queue *q = NULL;
    TNode *newNode = newTNode(data);
    q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    if (*root == NULL)
    {
        *root = newNode;
        return;
    }
    enQueue(q, *root);
    while (1)
    {
        TNode *n = NULL;
        void *node = dQueue(q);
        n = (TNode *)node;
        if (n->left == NULL)
        {
            n->left = newNode;
            return;
        }
        enQueue(q, n->left);
        if (n->right == NULL)
        {
            n->right = newNode;
            return;
        }
        enQueue(q, n->right);
    }
}

void preorder(TNode *root){
    if(root==NULL)
    {
     printf("Tree is empty");
     return;
    }
    
    SNode *top1=NULL;
    while(root!=NULL){
        int* res1=(int*)root->data;
        printf("%d\t", *res1);
    
        // printf("%d", *((int*)root->left->data));
        
        if(root->right!=NULL){
            push(&top1, root->right);
        }
        if(root->left!=NULL)
        {
            root=root->left;       
        }
        else {
            root=(TNode*)pop(&top1);
        }
        
        //  res1=(int*)root->data;
        // printf("%d\t", *res1);
        // printf("%d", *((int*)root->data));
        // int *t = (T)pop(&top1);
        // printf("%d", *((int*)((TNode*)pop(&top1))->data));
        // break;
    }
}
int stackisEmpty(SNode * top)
{
return top==NULL;

}

void postorder(TNode *root)
{
   // printf("func is start");
    if(root==NULL)
    {
        printf("EMPTY TREE");
        return;
    }
    SNode *s1=NULL;
    SNode *s2=NULL;
    while(root!=NULL)
    {
        push(&s1,root);
        if(root->left)
        {
            push(&s2,root->left);
        }
        if(root->right)
        {
            push(&s2,root->right);
        }
        root=(TNode*)pop(&s2);
    }
    while(!stackisEmpty(s1))
    {
        //printf("HELLO");
        TNode *temp=(TNode*)pop(&s1);
        int * data=(int *)temp->data;
        printf("%d\t",*data); 
    }
}

void inorder(TNode *root)
{
    SNode * top1=NULL;
    rstep:while(root!=NULL)
    {
        push(&top1,root);
        root=root->left;
    }
    root=(TNode*)pop(&top1);
    while(root!=NULL)
    {
        int * d=(int *)root->data;
        printf("%d",*d);
        if(root->right){
            root=root->right;
            goto rstep;
        }
        else{
            root=(TNode*)pop(&top1);
        }
    }
}

void r_preorder(TNode *root){
    int *d = (int*)root->data;
    printf("%d\t", *d);
    preorder(root->left);
    preorder(root->right);
}
void preorderR(TNode *root)
{

    if(root==NULL)
    {
        return;
    }
    int *res=(int *)root->data;
    printf("%d",*res);
   preorderR(root->left);
   preorderR(root->right);
}

int main()
{
    TNode *root = NULL;
    int a=10,b=20,c=30,d=40;

    insertBTree(&root, &a);
    
    insertBTree(&root, &b);
    insertBTree(&root, &c);
    
    //r_preorder(root);
    insertBTree(&root, &d);
    printf("Done!!\n");
  // preorder(root);
 // postorder(root);
 inorder(root);
 printf("Done!!\n");
 preorderR(root);
   // insertBTree(&root, 50);
    //insertBTree(&root, 60);
    //insertBTree(&root, 70);
       int *p=(int *)root->data;
     printf("\n%d\n", *p);
     p=(int*)root->left->data;
     printf("%d\n", *p);
     p=(int*)root->right->data;
     printf("%d\n",*p );
     p=(int *)root->left->left->data;
     printf("%d\n",*p );/*  */
   // printf("%d\n", root->left->right->data);

    //printf("%d\n", root->right->left->data);
    //printf("%d\n", root->right->right->data);
    // SNode *s1 = NULL;
    // int n = NULL;
    // push(&s1, &n);
    // push(&s1, &b);
    // int *t = (int*)pop(&s1);
    // printf("%d", *t);

    // t = (int*)pop(&s1);
    // printf("2nd =%d dsd", *t);

}