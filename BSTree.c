#include<stdio.h>
#include<stdlib.h>
typedef struct TNode{
    struct TNode * left;
    struct TNode * right;
    int data;
}TNode;
TNode * create(int data)
{
    TNode * newNode=malloc(sizeof(TNode));
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->data=data;
    return newNode;
}
void insertR(TNode **root,int data)
{
if(*root==NULL)
{
   *root=create(data);
   return;
}
if((*root)->data>data){
if((*root)->left==NULL)
{
(*root)->left=(TNode*)create(data);
return;
}
insertR(&((*root)->left),data);

}else
{
    if((*root)->right==NULL)
    {
        (*root)->right=create(data);
        return;
    }
    insertR(&((*root)->right),data);
}

}
void insertNR(TNode **root,int data)
{
 //TNode* newNode=create(data);   
 TNode *temp=*root;
 if(*root==NULL)
 {
     *root=create(data);
     return;
 }
 while(1){
 if(temp->data>data)
 {
     if(temp->left==NULL)
     {
         temp->left=create(data);
         return;
     }
     temp=temp->left;
 }else{
     if(temp->right==NULL)
     {
         temp->right=create(data);
         return;
     }
     temp=temp->right;
    }
}
 
}
void PrintAtK(TNode*root,int k)
{
    
    if(root==NULL)
    {
        printf("printing Element at %d level\n",k);
        printf("TREE IS EMPTY");
        return;
    }
    if(k<=1)
    {
        printf("printing Element at %d level->",k);
        printf("%d\n",root->data);
        return;
    }
    PrintAtK(root->left,k-1);
    PrintAtK(root->right,k-1);
}
int searchR(TNode* root,int data)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->data==data)
    {
        return 1;
    }
    if(root->data>data){
    searchR(root->left,data);
    }else{
    searchR(root->right,data);
    }
    //return -1;
}
int searchNR(TNode *root,int data)
{
   // TNode *temp=root;
    if(root==NULL)
    {
        return 0;
    }
    while(1)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(root->data==data)
        {
            return 1;
        }else
        {
            if(root->data>data)
            {
                root=root->left;
            }else{
                root=root->right;
            }


        }

    }
}
int minr(TNode* root)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->left==NULL)
    {
        return root->data;
    }
    minr(root->left);
}
int maxr(TNode* root)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->right==NULL)
    {
        return root->data;
    }
    maxr(root->right);
}
TNode * deleteR(TNode *root,int data)
{
    if(root==NULL)
    {
        free(root);
        return NULL;
    }
    if(root->data==data){
    if(root->left==NULL&&root->right==NULL)
    {
        return NULL;
    }
    if(root->left!=NULL)
    {
        int Maxd=maxr(root->left);
        root->data=Maxd;
        root->left= deleteR(root->left,Maxd);
        return root;
    }
    if(root->right!=NULL)
    {
        int Mind=minr(root->right);
        root->data=Mind;
        root->right=deleteR(root->right,Mind);
        return root;
    }
    }else{

    if(data<root->data)
    {
        root->left=deleteR(root->left,data);
        return root;
    }
        root->right=deleteR(root->right,data);
        return root;
    }
}

TNode * delete(TNode * root,int data){
    if(root==NULL){
        return NULL;
    }
    if(root->data == data){
        if(root->left ==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        if(root->left !=NULL){
            int maxD = maxr(root->left);
            root->data = maxD;
            root->left = delete(root->left,maxD);
            return root;
        }
        if(root->right!=NULL){
            int minD = minr(root->right);
            root->data = minD;
            root->right = delete(root->right,minD);
            return root;
        }
    }else{
        if(data<root->data){
         root->left = delete(root->left,data);
         return root;   
        }
        root->right = delete(root->right,data);
        return root;
    }
}

void preOrder(TNode * root){
    if(root==NULL){
        return;
    }
    printf("%d\t",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inorder(TNode * root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d\t",root->data);
     inorder(root->right);
}
int main()
{
    TNode *root=NULL;
    
    insertNR(&root,50);
    // printf("%d\n",root->data);
    insertNR(&root,30);
    // printf("%d\n",root->right->data);
    insertR(&root,70);
    insertR(&root,40);
    insertR(&root,60);
    preOrder(root);
    root=deleteR(root,70);
    printf("\n");
    preOrder(root);
    printf("\nminimum value is: %d\n",minr(root));
    printf("Maximum Value is : %d\n",maxr(root));
    // printf("%d\n",root->left->data);
    // insertNR(&root,40);
    // printf(root);
   // PrintAtK(root,2);
    // int res=searchR(root,50);
    // printf("%d",res);
    // if(searchR(root,50))
    // {
    //     printf("DATA FOUND\n");
    // }else printf("DATA NOT FOUND\n");
    // int res1=searchNR(root,10);
    // printf("%d",res1);
    // if(searchNR(root,50))
    // {
    //     printf("DATA FOUND\n");
    // }else printf("DATA NOT FOUND\n");
    // printf("minimum element in tree->%d",min(root));
inorder(root);
    return 0;

}