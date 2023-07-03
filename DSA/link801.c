#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;          // holds the actual data in a node
  struct node *next; // holds the address of the next node in the list
};
struct node *header = NULL;
struct node *getnode(int n) {
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  if (newnode == NULL) {
    printf("Memory allocation failed");
    // getche();
    exit(0);
  }
  newnode->data = n;
  newnode->next = NULL;
  return newnode;
}
void insertAtFront() {
  int n;
  struct node *ptrnew;
  printf("\nEnter a number");
  scanf_s("%d", &n);
  ptrnew = getnode(n);
  ptrnew->next = header;
  header = ptrnew;
  printf("\nNode inserted at the front.");
}
void insertAtLast() {
  int n;
  struct node *ptrnew, *ptrthis;
  printf("\nEnter a number:");
  scanf("%d", &n);
  ptrnew = getnode(n);
  if (header == NULL)
    header = ptrnew;
  else {
    for (ptrthis = header; ptrthis->next != NULL; ptrthis = ptrthis->next) {
      // do nothing
    }; // checks whether there is another list items or not
    ptrthis->next = ptrnew;
  }
  printf("\nNode inserted at the end.");
}
void insertAfter() {
  int n, target;
  struct node *ptrnew, *ptrthis;
  printf("\nEnter the number after which you want to insert.");
  scanf_s("%d", &target);
  for (ptrthis = header; ptrthis->next != NULL; ptrthis = ptrthis->next) {
    if (ptrthis->data == target) {
      printf("\nEnter your number");
      scanf_s("%d", &n);
      ptrnew = getnode(n);
      ptrnew->next = ptrthis->next;
      ptrthis->next = ptrnew;
      printf("\nNode inserted after %d", target);
      return;
    }
  };
  printf("\nTarget node not found.");
}

void insetBefore() {
  int n, target;
  struct node *ptrnew, *ptrthis, *ptrback;
  printf("\nEnter the number before which you want to insert.");
  scanf_s("%d", &target);
  for (ptrthis = ptrback = header; ptrthis != NULL; ptrthis = ptrthis->next) {
    if (ptrthis->data == target) {
      printf("\nEnter your number");
      scanf_s("%d", &n);
      ptrnew = getnode(n);
      if (ptrthis == header) {
        ptrnew->next = header;
        header = ptrnew;
      } else {
        ptrnew->next = ptrthis;
        ptrback->next = ptrnew;
      }
      ptrnew->next = ptrthis->next;
      ptrthis->next = ptrnew;
    }
    printf("\nNode inserted before %d", target);
    return;
    ptrback = ptrthis;
    ptrthis = ptrthis->next;
  };
  printf("\nTarget node not found.");
}
void remvoeFromFront() {
  struct node *ptrthis;
  if (header == NULL) {
    printf("\nList is empty.");
  } else {
    ptrthis = header;
    header = header->next;
    free(ptrthis);
    printf("Node removed form the front.");
  }
}
void remvoeFromLast() {
  struct node *ptrthis, *ptrback;
  if (header == NULL) {
    printf("List is empty.");
  } else {
    for (ptrthis = ptrback = header; ptrthis->next != NULL;
         ptrthis = ptrthis->next) {
      ptrback = ptrthis;
    }
    if (ptrthis == header) {
      header = NULL;
    } else {
      ptrback->next = NULL;
    }
    free(ptrthis);
    printf("\n Node removed form last");
  }
}
void removeAny(){
  int n;
  struct node *ptrthis, *ptrback;
  printf("\nEnter a number to be removed.");
  scanf_s("%d", &n);
  for(ptrthis=ptrback=header; ptrthis!=NULL; ptrthis=ptrthis->next){
    if (ptrthis->data==n) {
      // 3 cases we have to deal with
      if(ptrthis==header){
        header=header->next;
        free(ptrthis);
      } else {
      ptrback->next=ptrthis->next;
      }
      free(ptrthis);
      return;
    }
    ptrback=ptrthis;
  }
  printf("\nThe number you specified does not exist in the list.");
}
void display() {
  struct node *ptrthis;
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
  // struct node *header = NULL; // empty list initialized
  while (1) {
    system("CLS");
    printf("Select and option:\n1. Insert at front\n2.Insert at last "
           "\n3.Insert After \n4.Insert Before \n5.Remove from front "
           "\n6.Remove from last\n7. Remove any \n8. List \n9. Exit");
    ch = getchar();
    switch (ch) {
    case '1':
      insertAtFront();
      break;
    case '2':
      insertAtLast();
      break;
    case '3':
      insertAfter();
      break;
    case '4':
      insetBefore();
      break;
    case '5':
      break;
    case '6':
      break;
    case '7':
      break;
    case '8':
      display();
      break;
    case '9':
      exit(0);
    }
  }
  return 0;
}
