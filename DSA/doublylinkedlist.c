#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *next;
  struct node *prev;
};
struct node *header = NULL;
struct node *getnode(int n) {
  struct node *ptrnew = (struct node *)malloc(sizeof(struct node));
  if (ptrnew == NULL) {
    printf("\nMemory allocation failed.");
    _getch();
    exit(0);
  }
  ptrnew->data = n;
  ptrnew->next = ptrnew->prev = NULL;
  return ptrnew;
};

void insertAtFront() {
  struct node *ptrnew;
  int n;
  printf("\nEnter new number: ");
  scanf_s("%d", &n);
  ptrnew = getnode(n);
  if (header != NULL) {
    header = ptrnew;
  } else {
    ptrnew->next = header;
    header->prev = ptrnew;
  }
  header = ptrnew;
  printf("\nNode inserted at the front.");
}
void insertAtLast() {
  struct node *ptrnew, *ptrthis;
  int n;
  printf("\nEnter new nubmer: ");
  scanf_s("%d", &n);
  ptrnew = getnode(n);
  if (header == NULL) {
    header = ptrnew;
  } else {
    for (ptrthis = header; ptrthis->next != NULL; ptrthis = ptrthis->next)
      ;
    ptrthis->next = ptrnew;
    ptrnew->prev = ptrthis;
  }
  printf("\nNode inserted at the end.");
}

void insertAfter() {
  struct node *ptrnew, *ptrthis;
  int n, target;
  printf("\nEnter a node after which you want to inset: ");
  scanf_s("%d", &target);
  for (ptrthis = header; ptrthis != NULL; ptrthis = ptrthis->next) {
    if (ptrthis->data == target) {
      // insert and return
      printf("Enter a new number to be inserted: ");
      scanf_s("%d", &n);
      ptrnew = getnode(n);
      ptrnew->next = ptrthis->next;
      ptrnew->prev = ptrthis;
      if (ptrthis->next != ptrnew)
        (ptrthis->next)->prev = ptrnew;
      ptrthis->next=ptrnew;
      return;
    }
  }
}
void insertBefore() {
  struct node *ptrnew, *ptrthis;
  int n, target;
  printf("\nEnter a node after which you want to inset: ");
  scanf_s("%d", &target);
  for (ptrthis = header; ptrthis != NULL; ptrthis = ptrthis->next) {
    if (ptrthis->data == target) {
      // insert and return
      printf("Enter a new number to be inserted: ");
      scanf_s("%d", &n);
      ptrnew = getnode(n);
      ptrnew->prev = ptrthis->prev;
      ptrnew->next = ptrthis;
      if (ptrthis->prev != ptrnew)
        (ptrthis->prev)->next = ptrnew;
      ptrthis->prev=ptrnew;
      return;
    }
  }
}
