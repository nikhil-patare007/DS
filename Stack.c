#include<stdio.h>
#include<stdlib.h>

typedef struct SNode{
    int data;
    struct SNode *next;
}SNode;

SNode *createNode(int data){
   SNode *newNode = (SNode*)malloc(sizeof(SNode));
   newNode->data=data;
   newNode->next=NULL;
   return newNode;
}

void push(SNode **top, int data){
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

int pop(SNode **top){
    if(isEmpty(*top)){
        printf("\nStack is empty!!");
        return -1;
    }
    SNode *temp = *top;
    int data = temp->data;
    *top = temp->next;
    return data;
}
void printStack(SNode *top){
    while(top!=NULL){
        printf("%d\t", top->data);
        top=top->next;
   }
}


int main(){
    SNode *top=NULL;
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    printf("Stack elements are :");
    printStack(top);
    printf("\nStack elements after pop %d: ", pop(&top));
    printf("\nStack elements after pop %d: ", pop(&top));
    printStack(top);
    printf("\nStack elements after pop %d: ", pop(&top));
    printf("\nStack elements after pop %d: ", pop(&top));
    printStack(top);
    return 0;
}