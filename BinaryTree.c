#include <stdio.h>
#include <stdlib.h>
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
    struct SNode *left;
    struct SNode * right;
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
    printf("Stack is EMPTY");
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
int isEmptyStack(SNode *top){
    return top==NULL;
}

typedef struct TNode
{
    struct TNode *left;
    int  data;
    struct TNode *right;
} TNode;

TNode *newTNode(int data)
{
    TNode *newNode = (TNode *)malloc(sizeof(TNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void insertBTree(TNode **root, int data)
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
int max(TNode *root)
{
    if(root==NULL)
    {
        return -1;
    }
    int lmax=max(root->left);
    int rmax=max(root->right);
    int max=lmax>rmax?lmax:rmax;
    if(max>root->data)
    {
        return max;
    }
    return root->data;
}
int identical(TNode *t1,TNode *t2)
{
    if(t1==NULL&&t2==NULL)
    {
        return 1;
    }
    if(t1==NULL||t2==NULL)
    {
        return 0;
    }
    int li=identical(t1->left,t2->left);
    int ri=identical(t1->right,t2->right);
    return li&&ri&&(t1->data==t2->data); 
}
int miror(TNode *t1,TNode *t2)
{
    if(t1==NULL&&t2==NULL)
    {
        return 1;
    }
    if(t1==NULL||t2==NULL)
    {
        return 0;
    }
    int li=miror(t1->left,t2->right);
    int ri=miror(t1->right,t2->left);
    return li&&ri&&(t1->data==t2->data);
}

void postorder(SNode * root){
    if(root==NULL){
        return;
    }
    SNode * s1=NULL;
    SNode * s2=NULL;
    while(root!=NULL){
        push(&s1,root);
        if(root->left){
            push(&s2,root->left);
        }
        if(root->right){
            push(&s2,root->right);
        }
    root=(TNode*)pop(&s1);
    }
while(!isEmptyStack(s1)){
    TNode * temp=(TNode*)pop(&s1);
    int *data =(int*)temp->data;
     printf("%d\t",*data);
    
}

}
int main()
{
    TNode *root = NULL;
    TNode *root1 = NULL;
    int a=10,b=20,c=30,d=40;

    insertBTree(&root, 10);
    insertBTree(&root, 20);
    insertBTree(&root, 30);
    insertBTree(&root, 40);
    // insertBTree(&root, 50);
    // insertBTree(&root, 60);
    // insertBTree(&root, 70);
    // // 2nd TREE 
    // insertBTree(&root1, 10);
    // insertBTree(&root1, 20);
    // insertBTree(&root1, 30);
    // insertBTree(&root1, 40);
    // insertBTree(&root1, 50);
    // insertBTree(&root1, 60);
    // insertBTree(&root1, 70);

      //int *p=(int *)
//     printf("%d\n", root->data);
//    // p=(int*)root->left->data;
//     printf("%d\n", root->left->data);
//     //p=(int*)root->right->data;
//     printf("%d\n",root->right->data );
//    // p=(int *)root->left->left->data;
//     printf("%d\n",root->left->left->data );
//    // p=(int*);
//     printf("%d\n",root->left->right->data);
//   //  p=(int*)root->right->left->data;
//     printf("%d\n",root->right->left->data);
//     //p=(int *)root->right->right->data;
//     printf("%d\n",root->right->right->data);
  // printf("MAXIMUM VALUE IN BTREE IS->%d\n", max(root));
   
   /*if(identical(root,root1))
   {
       printf("TREES ARE IDENTICAL\n");
   }else printf("TREES ARE NOT IDENTICAL\n");

   if(miror(root,root1))
   {
       printf("TREES ARE MIRROR IMAGES OF EACH OTHER\n");
   }else printf("TREES ARE NOT MIRROR IMAGAE OF EACH OTHER\n");
*/
printf("\nPostorder :");
    postorder(root);
    return 0;
}