// prefix expression
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <process.h>
#include <math.h>
#define MAX 100 
typedef struct {
  float items [MAX];
  int tos;
} stack;
void push (stack* s, float val){
  s->items[++s->tos]=val;
}
float pop(stack* s){
  return s->items[s->tos--];
}
int main(){
  int i; 
  float op1, op2, val;
  stack s;
  char str[MAX];
  s.tos=-1;
  printf("Enter your prefix expression: ");
  scanf("%s",str);
  /* fgets(str, MAX, stdin); */ // occurs problem when using fgets
  for (i=strlen(str)-1; i>=0; i--){
    switch (str[i]) {
      case '+':
      op1=pop(&s);
      op2=pop(&s);
      push(&s, op1+op2);
      break;

      case '-':
      op1=pop(&s);
      op2=pop(&s);
      push(&s, op1-op2);
      break;

      case '*':
      op1=pop(&s);
      op2=pop(&s);
      push(&s, op1*op2);
      break;

      case '/':
      op1=pop(&s);
      op2=pop(&s);
      push(&s, op1/op2);
      break;

      case '$':
      op1=pop(&s);
      op2=pop(&s);
      push(&s,pow(op1, op2));
      break;

     default:
      printf("Enter the value of %c",str[i]);
      scanf("%f",&val);
      push(&s,val);
      break;    
    }
  }
printf("\n Value of the expression: %f",pop(&s));
getche();
}

















