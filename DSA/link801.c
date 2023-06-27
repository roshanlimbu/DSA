#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;          // holds the actual data in a node
  struct node *next; // holds the address of the next node in the list
};
struct node *getnode() {
  int n;
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = n;
  newnode->next = NULL;
  return newnode;
}
void insertAtLast() {
  int n;
  struct node *ptr, *ptrthis;
  printf("\nEnter a number:");
  scanf("%d", &n);
  ptr = getnode(n);
  if (header == NULL)
    header = ptrnew;
  else {
    for (ptrthis = header; ptrthis->next != NULL; ptrthis = ptrthis->next)
      ;
    ptrthis->next = ptrnew;
  }
  printf("\nNode inserted at the end");
}
void display() {
  if (header == NULL)
    printf("\nList is empty");
  else {
    for (ptrthis = header; ptrthis != NULL; ptrthis = ptrthis->next) {
      printf("%d\t", ptrthis->data);
    }
  }
}
int main() {
  char ch;
  struct node *header = NULL; // empty list initialized
  while (1) {
    system("clear");
    printf("Select and option:\n1. Insert\n2. Remove\n3. List\n4. Exit");
    ch = getchar();
    switch (ch) {
    case '1':
      insertAtLast();
      break;
    case '2':
      break;
    case '3':
      display();
      break;
    case '4':
      break;
    }
  }
  return 0;
}
