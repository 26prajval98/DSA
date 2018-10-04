#include <stdio.h>
#include <stdlib.h>
// A program useful for executing delete insert operations on BST
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

Node* createNode(int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int findMin(Node* root){
    while(root->left!=NULL){
        root = root->left;
    }
    //printf("test - %d",root->data);
    return root->data;
}

Node* binaryInsert(Node* root, int data){
    if(root == NULL){
        root = createNode(data);
    }
    else{
        if(data>root->data){
            root->right = binaryInsert(root->right,data);
        }
        else{
            root->left = binaryInsert(root->left,data);
        }
    }
    return root;
}


Node* delNode(Node* root, int data){
    if(root == NULL){
        return root;
    }
    else{
        if(data<root->data){
            root->left = delNode(root->left,data);
        }
        else if(root->data<data){
            root->right = delNode(root->right,data);
        }
        else{
            if(root->left == NULL && root->right == NULL){
                free(root);
                root = NULL;
            }
            else if(root->left == NULL){
                Node* temp = root;
                free(temp);
                root = root->right;
            }
            else if(root->right == NULL){
                Node* temp = root;
                free(temp);
                root = root->left;
            }
            else{
                int min = findMin(root->right);
                root->data = min;
                root->right = delNode(root->right,min);
            }
        }
        return root;
    }
}

void printInorder(Node* root){
    if(root!=NULL){
        printInorder(root->left);
        printf("%d ",root->data);
        printInorder(root->right);
    }
}

int main(){
    Node* root = NULL;
    int data;
    while(1){
        printf("Enter 1.Insert 2.Delete: ");
        int x;
        scanf("%d",&x);
        if(x==1){
            printf("Enter data: ");
            scanf("%d",&data);
            root = binaryInsert(root,data);
            //printf("%d dae",root->data);
        }
        else if(x==2){
            printf("Enter data: ");
            scanf("%d",&data);
            root = delNode(root,data);
            //printf("%d dae",root->data);
        }
        else{
            break;
        }
        printInorder(root);
        printf("\n");
    }
}
