#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

//create new node
Node* createNewNode(int data){
    struct Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// in order traversal 
void inOrderTraversal(Node *root){
    if(root!=NULL){
        printf("%d", root->data);
        inOrderTraversal(root->left);
        inOrderTraversal(root->right);
    }
}


int main(){
    struct Node *root;
    createNewNode(1);

    root->left= createNewNode(2);
    root->right= createNewNode(3);
    root->left->left= createNewNode(4);
    root->right->right= createNewNode(5);


    printf("Inorder Traversal: \n");
    inOrderTraversal(root);


    return 0;
}









