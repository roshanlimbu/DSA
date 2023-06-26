#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
  char data[MAX_SIZE][MAX_SIZE];
  int top;
} Stack;

void initialize(Stack *stack) { stack->top = -1; }

bool isEmpty(const Stack *stack) { return stack->top == -1; }

bool isFull(const Stack *stack) { return stack->top == MAX_SIZE - 1; }

void push(Stack *stack, const char *value) {
  if (isFull(stack)) {
    printf("Stack overflow!\n");
    exit(EXIT_FAILURE);
  }

  stack->top++;
  strcpy(stack->data[stack->top], value);
}

char *pop(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack underflow!\n");
    exit(EXIT_FAILURE);
  }

  return stack->data[stack->top--];
}

void postfixToInfix(const char *postfix, char *infix) {
  Stack stack;
  initialize(&stack);

  int i = 0;
  while (postfix[i] != '\0') {
    char ch = postfix[i];

    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
      char operand[2];
      operand[0] = ch;
      operand[1] = '\0';
      push(&stack, operand);
    } else {
      char op1[MAX_SIZE], op2[MAX_SIZE], temp[MAX_SIZE];

      strcpy(op2, pop(&stack));
      strcpy(op1, pop(&stack));

      sprintf(temp, "(%s%c%s)", op1, ch, op2);

      push(&stack, temp);
    }

    i++;
  }

  strcpy(infix, pop(&stack));
}

int main() {
  char postfix[MAX_SIZE];
  char infix[MAX_SIZE];

  printf("Enter the postfix expression: ");
  scanf("%s", postfix);

  postfixToInfix(postfix, infix);

  printf("Infix expression: %s\n", infix);

  return 0;
}
