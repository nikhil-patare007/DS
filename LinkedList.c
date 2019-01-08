//
// Created by nikhil on 10/7/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void addNode(Node **root, int data) {
    Node *temp;
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*root == NULL) {
        *root = newNode;
        return;
    }
    temp = *root;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void dispalyData(Node *root) {
    while (root != NULL) {
        printf("%d\n", root->data);
        root = root->next;
    }
}

void displayRecursive(Node *root) {
    Node *temp = (root);
    if (temp == NULL) {
        return;
    }
    printf("%d\n", temp->data);

    displayRecursive(temp->next);

}

void displayRecursiveReverse(Node *root) {

    if (root == NULL) {
        return;
    }

    displayRecursiveReverse(root->next);
    printf("%d\n", root->data);
}


Node *searchNode(Node *root, int data) {
    while (root != NULL && root->data != data) {
        root = root->next;
    }
    return root;
}

Node *searchIndexRecursive(Node *root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == data) {
        return root;
    }
    return searchIndexRecursive(root->next, data);
}

Node *searchRecursiveReverse(Node *root, int data) {
    Node *res = NULL;
    if (root == NULL) {
        return NULL;
    }
    res = searchRecursiveReverse(root->next, data);
    if (res != NULL) {
        return res;
    }
    if (root->data == data) {
        return root;
    }
    return NULL;

}

int count(Node *root) {
    int count = 0;
    while (root != NULL) {
        root = root->next;
        count++;
    }
    return count;
}

Node *nodeAt(Node *root, int index) {
    while (root != NULL && index != 0) {
        root = root->next;
        index--;
    }
    if (index != 0) {
        return NULL;

    }
    return root;
}

int middleElement(Node *root) {
    int cnt = count(root);
    int res = floor(cnt / 2);
    Node *result1 = nodeAt(root, res);
    return result1->data;

}

int middlenBy2Complexity(Node *root) {
    Node *fast = root;
    Node *slow = root;
    if (root == NULL) {
        return -1;
    }

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow->data;
}


void insertAtFirst(Node **root, int data) {
    Node *newNode = createNode(data);
    newNode->next = *root;
    *root = newNode;
}

int insertAfter(Node *root, int data, int dataAfter) {
    Node *temp = searchRecursiveReverse(root, dataAfter);
    Node *newNode = createNode(data);
    if (temp == NULL) {
        return -1;
    }
   // newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    return newNode->data;
}

void insertBefore(Node **root, int data , int dataBefore ){
    Node* temp= *root;

    Node * newNode= createNode(data);
    if(*root==NULL){
        *root=newNode;
        return ;
    }
if(temp->data==dataBefore){
     insertAtFirst(&temp,data);
}
    while(temp->next!=NULL && temp->next->data!=dataBefore){
        temp=temp->next;
        }
          newNode->next=temp->next;
         temp->next=newNode;
        // printf("%d",newNode->data);
       return;
 }
 void deleteNode(Node ** root, int data){
        Node * temp= *root;
    if(*root==NULL){
        printf("List is empty\n");
    }
     
    Node* toBeDelete=temp;

    if(temp->data==data){
        *root=temp->next;
        free(toBeDelete);
        return;
    }
    while(temp->next!=NULL && temp->next->data!=data){
        temp=temp->next;
    }
    if(temp->next==NULL){
    printf("\nNode to be delete not found.!");
        return;
    }
    
    toBeDelete = temp->next;
    temp->next=temp->next->next;
    free(toBeDelete);
     return;
}

Node* findNthNodeFromLast(Node * root, int n){
    Node * p1,*p2;
    p1=root;
    p2=root;
    while(p1!=NULL && n!=0){
        p1=p1->next;
        n--;
    }
    if(p1==NULL){
        return NULL;
    }
    while(p1->next!=NULL){
        p1=p1->next;
        p2=p2->next;
       
    }
return p2;
}
int isLoopPresent(Node *root){
    Node * f=root;
    Node * s=root;
    if(root==NULL){
        return -1;
    }
    do{
        s=s->next;
        f=f->next;
         if(f!=NULL){
             f=f->next;
         }
    }while(s!=f&& f!=NULL);
    return f==NULL ? -1:1;
}
void removeLoop(Node * loopNode, Node * root){
Node* fast;
Node * slow;
slow=root;
while (slow!=fast->next){
slow=slow->next;
fast=fast->next;
}
fast->next=NULL;
}


void something(Node * root) {
    if (root == NULL) {
        printf("\n...done");
        return;
    }
        printf("%d\t", root->data);
        something(root->next);
        printf("%d\t", root->data);

}
int main() {
    Node *root = NULL;
    // int count=0;
    int ch = 1, num = 0, index1 = 0,data=0 , n=0;
    do {
        printf("1.Create node\n");
        printf("2.Add node\n");
        printf("3.Display data\n");
        printf("4.Display Recursively data\n");
        printf("5.Display Recursively Reverse data\n");
        printf("6.Search index of data\n");
        printf("7.Search index of data recursively\n");
        printf("8.Search index of data recursively reverse\n");
        printf("9.Count the nodes\n");
        printf("10.find data of Node \n");
        printf("11.Middle of the node\n");
        printf("12.Middle of the node by n/2 complexity\n");
        printf("13.Insert at first\n");
        printf("14.Insert After the node\n");
        printf("15.Insert before the node\n");
        printf("16.Enter data to delete node\n");
        printf("17.Enter index to find nth node\n");
        printf("18.Is loop present \n");
        printf("19.Something \n");
        printf("20.Exit.\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter node to  create......\n");
                scanf("%d", &num);
                createNode(num);
                printf("***********************************************************************\n");

            case 2:

                printf("Enter node to add......\n");
                scanf("%d", &num);
                addNode(&root, num);
                printf("***********************************************************************\n");
                break;
            case 3:
                printf("Displaying data.......\n");
                dispalyData(root);
                printf("***********************************************************************\n");

                break;
            case 4:
                printf("Displaying Recursively\n");
                displayRecursive(root);
                printf("***********************************************************************\n");
                break;
            case 5:
                printf("Displaying Recursively Reverse\n");
                displayRecursiveReverse(root);
                printf("***********************************************************************\n");
                break;
            case 6:
                printf("Enter data to find index......\n");
                scanf("%d", &num);

                searchNode(root, num);
                printf("Searching index ..\n");
                if (root == NULL) {
                    printf("Not found\n");
                }
                printf("data found\n");
                printf("***********************************************************************\n");
                break;
            case 7:
                printf("Enter data to find index......\n");
                scanf("%d", &num);
                printf("Find data recursively..");
                Node *res = searchIndexRecursive(root, num);
                if (res == NULL) {
                    printf("Not found\n");
                }
                printf("data found\n");
                printf("***********************************************************************\n");

                break;
            case 8:

                printf("Enter node to find data......\n");
                scanf("%d", &num);
                printf("Find data recursively reverse..");
                Node *res1 = searchRecursiveReverse(root, num);
                if (res1 == NULL) {
                    printf("Not found\n");
                }
                printf("data found\n");
                printf("***********************************************************************\n");

                break;
            case 9:
                printf("Total number of nodes are.. ");
                printf("%d\n", count(root));
                printf("***********************************************************************\n");

                break;
            case 10:

                printf("Enter data the index......\n");
                scanf("%d", &index1);
                printf("Node found is..\n");
                Node *res2 = nodeAt(root, index1);
                printf("%d\n", res2->data);
                printf("***********************************************************************\n");

                break;
            case 11:
                printf("Middle of the node is\n");
                printf("%d\n", middleElement(root));
                printf("***********************************************************************\n");

                break;
            case 12:
                printf("Middle of the node by n/2 complexity\n");
                printf("%d\n", middlenBy2Complexity(root));
                printf("***********************************************************************\n");

                break;
            case 13:

                printf("enter to Insert At first\n");
                scanf("%d", &num);
                insertAtFirst(&root,num);
                printf("***********************************************************************\n");

                break;
            case 14:
                printf("Enter data to after which you wanna insert\n");
                scanf("%d",&data);
                printf("Enter data to insert after\n");
                scanf("%d", &num);
                printf("%d",insertAfter(root,data,num));
                printf("***********************************************************************\n");

                break;
            case 15:
                printf("Enter data before wich you want to insert\n");
                scanf("%d", &num);
                printf("Enter data you want to insert\n");
                scanf("%d", &data);

                insertBefore(&root,data,num);
                printf("***********************************************************************\n");

                break;
            case 16:
                printf("Enter data you want to delete\n");
                scanf("%d", &data);
                deleteNode(&root,data);
                printf("***********************************************************************\n");
                break;
            case 17:
                printf("Enter index from last to find nth node from last\n");
                scanf("%d", &n);
                Node * res4=findNthNodeFromLast(root,n);
                printf("%d",res4->data);
                printf("***********************************************************************\n");
                break;
            case 18:
                printf("Is loop present\n");
                 int n=isLoopPresent(root);
                if(n){
                    printf("\nNo ");
                } else printf("\nyes");
                printf("***********************************************************************\n");
                break;
            case 19:
                printf("Something function\n");
                something(root);
                printf("***********************************************************************\n");
                break;

            case 20:
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
    } while (ch != 20);
    return 0;
}