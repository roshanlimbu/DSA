#include <stdio.h>
#include <stdlib.h>

#define TRUE 1

struct node{
    int info;
    struct node *left;
    struct node *right;

};

struct node *root = NULL; // empty binary tree


struct node *getNode (int d){
    struct node*ptrnew=(struct node *)malloc(sizeof(struct node));
    if(ptrnew== NULL){
        printf("Fatal Error: memory allocation failed.");
        getchar();
        exit(0);
    }
    ptrnew->info=d;
    ptrnew->left=ptrnew->right=NULL;
    return ptrnew;
};

void insertNode(){
    int data;
    struct node*ptrnew, *ptrthis= root;
    printf("Enter the data to be inserted: ");
    scanf("%d", &data);
    ptrnew=getNode(data);
    if(root==NULL){
        root = ptrnew;
        printf("\nNode inserted at the root position.");
    } else {
        ptrthis=root;
        while(ptrthis!=NULL){
            if(data<ptrthis->info){
                if(ptrthis->left==NULL){
                    ptrthis->left=ptrnew;
                    break;
                } else {
                    ptrthis=ptrthis->left;
                }
            } else{
                if(ptrthis->right==NULL){
                    ptrthis->right=ptrnew;
                    break;
                } else {
                    ptrthis=ptrthis->right;
                }
            }
            printf("\nData inserted.");
        }
    }
}


void removeNode(){
    int data;
    struct node *ptrthis, *ptrparent=NULL;
    printf("Enter the number to be removed");
    scanf("%d", &data);

    ptrthis=root;
    while(ptrthis!=NULL){
        if(ptrthis->info==data){
            // this is the node to be removed
            if(ptrthis->left==NULL && ptrthis->right == NULL ) {
                if(ptrthis==root){
                    root=NULL;
                } else if(ptrparent->left==ptrthis){
                    ptrparent->left=NULL;
                } else {
                    ptrparent->right=NULL;
                }
                free(ptrthis);
            }
            else if(ptrthis->left==NULL){ // if node has only right son
                if(ptrparent->left==ptrthis){ // if deleted node is left son
                    ptrparent->left=ptrthis->right;
                } else {
                    ptrparent->right=ptrthis->right;
                }

            } else if (ptrthis->right==NULL){
                if(ptrparent->left==ptrthis){ // if deleted node is left son
                    ptrparent->left=ptrthis->left;
                } else {
                    ptrparent->right=ptrthis->left;
                }

            } else { // if node has both left and right son
                while (ptrthis) {
        
                }

            }

        } else if(ptrthis->info>data){
            ptrparent=ptrthis;
            ptrthis=ptrthis->left;
        } else {
            ptrparent=ptrthis;
            ptrthis=ptrthis->right;
        }
    }
    printf("\n%d does not exist in the tree", data);
}
void Display(){

}


void preorder(struct node *r){
    if(r!=NULL){
        printf("%d", r->info);
        preorder(r->left);
        printf("%d", r->info);
        preorder(r->right);
    };

}
void inorder(struct node *r){
    if(r!=NULL){
        inorder(r->left);
        printf("%d", r->info);
        inorder(r->right);
    }

}

void Search(){
    int data;
    struct node *ptrthis=root;
    printf("Enter a number to search: ");
    scanf("%d",&data );
    while(ptrthis!=NULL){
        if(ptrthis->info==data){
            printf("%d exists in the tree." , data);
            return;
        } else if(ptrthis->info>data){
            ptrthis=ptrthis->left;
        } else {
            ptrthis=ptrthis->right;
        }
    }
    printf("%d does not exist in the tree. ", data);
}

void Exit(){

}

int main(){
    char ch;

    while (TRUE) {
        printf("Select your choice.\n");
        printf("1. Add \n2. Remove \n3. Display \n4. Preorder \n5. Postorder")    ;
        printf("\n6. Search \n7. Exit");

        fflush(stdin);
        ch=getchar();
        switch (ch) {

            case '1': insertNode(); break;
            case '2': break;
            case '3': printf("Tree contains: \n"); inorder(root); printf("\n"); break;
            case '4': printf("Tree contains: \n"); preorder(root); printf("\n"); break;
            case '5': break;
            case '6': break;
            case '7': break;
        }
        getchar();
    }
    return 0;
}
