#include <stdio.h>
#include <conio.h>
#define MAX 10
#include <process.h>
typedef struct {
  int num[MAX];
  int tos; 
} stack;
int isEmpty(stack* sp){
  if(sp->tos==-1){
    return -1;
  } else {
    return  0;
  }
}
int isFull(stack* sp){
  if(sp->tos==MAX-1){
    return 1;
  } else {
    return 0;
  }
}
void push (stack * sp){
  if(isFull(sp)){
    printf("Stack is full");
    exit(0);
  } else {
    // sp->tos++;
    // sp->num[sp->tos] = n;
    sp->num[++sp->tos]= n; // pushing after increasing the stack by 1
  }
}
void pop(stack* sp){
  if(isEmpty(sp)){
    printf("Stack Underflow.\n");
    return;
  }
  n= sp->num[sp->tos];
  sp->tos--;
  printf("%d was popped.", n);
}
