#include<stdio.h>
#include<stdlib.h>

typedef struct SNode{
    void * data;
    struct SNode *next;
}SNode;
typedef struct TNode{
    void * data;
    struct TNode* left;
    struct TNode * right;

}TNode;

SNode *createNode(void * data){
   SNode *newNode = (SNode*)malloc(sizeof(SNode));
   newNode->data=data;
   newNode->next=NULL;
   return newNode;
}

void push(SNode **top, void * data){
    SNode *newNode = createNode(data);
    if(*top==NULL){
       *top = newNode;
       return;
    }
    newNode->next=*top;
    *top=newNode;
}

int isEmpty(SNode *top){
    return top==NULL;
}

void * pop(SNode **top){
    if(isEmpty(*top)){
        printf("\nStack is empty!!");
        return NULL;
    }
    SNode *temp = *top;
    void * data = temp->data;
    *top = temp->next;
    return data;
}
void preorder(TNode *root){
    if(root==NULL){
        printf("Tree is Empty bro !");
   }
   TNode * newNode=createNode(NULL);
   push(&top,createNode(NULL));
   while(root!=NULL){
       printf("%d",root->data);
       if(root->right!=NULL)
       push(&top, root->right);
       else if(root->left!=NULL)
       root=root->left;
       else
       root=pop(&top);
        
       
   }

}
// void inorder(TNode * root){
// if(root==NULL){
//         printf("Tree is Empty bro !");
//    }
//    TNode * newNode=createNode(top);
//    push(&top,root->data); 
//    while(root!=NULL){
      
//        if(root->left!=NULL)
//        push(&top, root->right);
//        push(&top, root);
//        else if(root->left!=NULL)
//        push(&top,root->left);
//        root=root->left;
//        else 
//        root=pop(&top);
//        printf("%d",root->data);
//    }

// }
int main()
{
  SNode *top=NULL;
  int a=10;
  int b=20;
  int c=30;
    push(&top, &a);
    push(&top, &b);
    push(&top, &c);
    printf("Stack elements are :");
    void * data1 = pop(&top);
     int d=(int)data1;
    // printStack(top);
   printf("\nStack elements after pop %d: ", d);
//     printf("\nStack elements after pop %d: ", pop(&top));
//    // printStack(top);
//     printf("\nStack elements after pop %d: ", pop(&top));
//     printf("\nStack elements after pop %d: ", pop(&top));
   // printStack(top);
    return 0;
}