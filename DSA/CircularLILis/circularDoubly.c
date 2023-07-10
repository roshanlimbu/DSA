#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node {
  int info;
  struct node *next;
  struct node *prev;
};

struct node *header = NULL;
struct node *getnode(int n){
  struct node *ptrnew=(struct node*)malloc(sizeof(struct node));
  if(ptrnew==NULL){
    printf("\nMemory allocation failed.");
    getch();
    exit(0);
  }
  ptrnew->info=n;
  ptrnew->next = ptrnew->prev=NULL;
  return ptrnew;
}
void insertAtFront(){
  int n;
  struct node *ptrnew;

  printf("\nEnter new number");
  scanf_s("%d",&n);
  ptrnew = getnode(n);
  if(header ==NULL){
    header=ptrnew;
    header->next=header->prev=header;
  } else{
    ptrnew->next=header;
    ptrnew->prev=header->prev;
    (header->prev)->next=ptrnew;
    header->prev=ptrnew;
    header=ptrnew; // comment this out for making this func insetAtLast function
  } 
  printf("\nNode inserted at the front.");
}
void insertAtLast(){
  int n;
  struct node *ptrnew;

  printf("\nEnter new number");
  scanf_s("%d",&n);
  ptrnew = getnode(n);
  if(header ==NULL){
    header=ptrnew;
    header->next=header->prev=header;
  } else{
    ptrnew->next=header;
    ptrnew->prev=header->prev;
    (header->prev)->next=ptrnew;
    header->prev=ptrnew;
  } 
  printf("\nNode inserted at the front.");
}

void insertAfter(){
  int n,key;
  struct node *ptrthis, *ptrnew;
  if(header==NULL){
    printf("\nList is empyt.");
    return;
  }
  printf("\nEnter a number after which you want to add new node");
  scanf("%d", &key);
  ptrthis=header;
  do{
   if(ptrthis->info==key) {
      printf("\nEnter new node to be inserted");
      scanf("%d", &n);
      ptrnew=getnode(n);
      ptrnew->prev=ptrthis;
      ptrnew->next=ptrthis->next;
      (ptrthis->next)->prev=ptrnew;
      ptrthis->next=ptrnew;
      printf("\nNode inserted after %d", key);
      return;
    }
    ptrthis=ptrthis->next; // go ahead
  } while(ptrthis!=header);
  printf("%d not found in the list.", key);
}
void insertBefore(){
  int n,key;
  struct node *ptrthis, *ptrnew;
  if(header==NULL){
    printf("\nList is empyt.");
    return;
  }
  printf("\nEnter a number before which you want to add new node");
  scanf("%d", &key);
  ptrthis=header;
  do{
   if(ptrthis->info==key) {
      printf("\nEnter new node to be inserted");
      scanf("%d", &n);
      ptrnew=getnode(n);
      ptrnew->prev=ptrthis->prev;
      ptrnew->next=ptrthis;
      (ptrthis->prev)->next=ptrnew;
      ptrthis->prev=ptrnew;
      if(ptrthis==header){
        header = ptrnew;
      }
      printf("\nNode inserted before %d", key);
      return;
    }
    ptrthis=ptrthis->next; // go ahead
  } while(ptrthis!=header);
  printf("%d not found in the list.", key);
}
void forwardDisplay(){
  struct node *ptrthis;
  if(header==NULL){
    printf("\nList is empty.");
  } else {
    printf("\nList contains: \n");
    ptrthis=header;
    do{
      printf("%d\t", ptrthis->info);
      ptrthis=ptrthis->next;

    } while(ptrthis!=header);
  }
}

void backwardDisplay(){
  struct node *ptrthis;
  if(header==NULL){
    printf("\nList is empty.");
  } else {
    printf("\nList contains: \n");
    ptrthis=header->prev;
    do{
      printf("%d\t", ptrthis->info);
      ptrthis=ptrthis->prev;

    } while(ptrthis!=header->prev);
  }
}
int main(){
  char ch;
  do{
    printf("Enter your choice: \n1. Insert at front \n2. Insert at end \n");
    printf("3.Insert after: \n4. Insert before \n5. Remove from the front \n");
    printf("6. Remove from the last \n7. Remvoe any \8. Display Forward\n");
    printf("9. Display backward \nX. Exit");
    ch=getche();
    switch(ch){
      case '1': insertAtFront(); break;
      case '2': insertAtLast(); break;
      case '3': insertAfter(); break;
      case '4': insertBefore(); break;
      case '5': break;
      case '6': break;
      case '7': break;
      case '8': forwardDisplay();break;
      case '9': backwardDisplay();break;
      case 'x':
    }
    getch();
  } while(1);
  return 0;
}

