#include <stdio.h>
#include <conio.h>
#include <process.h>
#define MAX 10
#define TRUE 1
#define FALSE 0 
typedef struct stack{
  int num[MAX];// array is used as to store-house for stack
  int tos; // top of the stack
} stack;
int isEmpty( stack* s){
  if(s->tos==-1){
    return TRUE;
  } else{
    return FALSE;
  }
}
int isFull( stack* s){
  if(s->tos==MAX-1){
    return TRUE;
  } else{
    return FALSE;
  }
}
void list(stack s){
  int i; 
  if(isEmpty(&s)){
    printf("Stack is empty");
  } else{
    printf("\n Stack contains: \n");
    for (i=s.tos; i>=0; i--){
      printf("%d\n", s.num[i]);
    }
  }
  
}
void push ( stack* s){
  int n; 
  if (isFull(s)){
    printf("Stack is full. You cannot push more items.");
    return;
  }
  printf("Enter a number");
  scanf("%d", &n);
  s-> tos++;
  s->num[s->tos]=n;
  printf("Item pushed ontop of the stack");
}
void pop(stack *s){
  int n; 
  if(isEmpty(s)){
    printf("Stack is empty. YOu cannot pop more items.");
    return;
  }
  n=s->num[s->tos];
  s->tos--;
  printf("%d was popped out ", n);
}
void main(){
  stack s;
  char choice;
  s.tos=-1;
  while(TRUE){
    system("cls");
    printf("Select an option: \n");
    printf("1. Push \n 2. Pop \n 3. List \n4. Exit");
    fflush(stdin);
    choice=getche();
    system("cls");
    switch (choice) {
      case '1': push(&s); break;
      case '2': pop(&s); break;
      case '3': list(s); break;
      case '4': return; 
    }
    getch();
  }
}














