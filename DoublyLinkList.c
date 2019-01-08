#include<stdio.h>
#include<stdlib.h>
typedef struct DLNode{
    int data;
    struct DLNode *next;
    struct DLNode * prev;
}DLNode;
 
DLNode* createNode(int data){
    DLNode * newNode =(DLNode*)malloc (sizeof(DLNode));
    newNode->data=data;
    newNode->prev=NULL; 
    newNode->next=NULL;
    return newNode;
 }
void addDlNode(DLNode ** root, int data){
    DLNode *temp;
    DLNode *newNode = (DLNode *) malloc(sizeof(DLNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev=NULL;
     if (*root == NULL) {
        *root = newNode;
        return;
    }
    temp = *root;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    newNode->prev=temp;
    temp->next = newNode;
}
void displayData(DLNode *root){
    while(root!=NULL){
        printf("%d\n",root->data);
        root=root->next;
    }
}
void displayRecursive(DLNode *root) {
    DLNode *temp = (root);
    if (temp == NULL) {
        return;
    }
    printf("%d\n", temp->data);
    displayRecursive(temp->next);

}
int main() {
    DLNode *root = NULL;
    int ch = 1,num=0;
    do {

        printf("1.Add node\n");
        printf("2.Display data\n");
        printf("3.Display data recursively\n");
        printf("4.Exit.\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:

                printf("Enter node to add......\n");
                scanf("%d",&num);
                addDlNode(&root,num);
                printf("***********************************************************************\n");
                break;
            case 2:
                printf("Displaying data.......\n");
                displayData(root);
                printf("***********************************************************************\n");

                break;
            case 3:
                printf("Displaying data recursively.......\n");
                displayRecursive(root);
                printf("***********************************************************************\n");

                break;
            case 4:
                printf("Exit.\n");
                printf("***********************************************************************\n");

                exit(1);

                break;

            default:
                printf("Enter valid choice\n");
                break;
        }
        printf("Do u want to continue?(1 for continue)");
        scanf("%d", &ch);
    } while (ch != 4);
    return 0;
}