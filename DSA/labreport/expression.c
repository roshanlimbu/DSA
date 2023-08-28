#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

// Structure to represent a stack
typedef struct {
    int top;
    char items[MAX_SIZE];
} Stack;

// Function to initialize the stack
void initializeStack(Stack* stack) {
    stack->top = -1;
}

// Function to check whether the stack is empty
bool isStackEmpty(Stack* stack) {
    return (stack->top == -1);
}

// Function to check whether the stack is full
bool isStackFull(Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Function to push an item onto the stack
void push(Stack* stack, char item) {
    if (isStackFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }

    stack->items[++stack->top] = item;
}

// Function to pop an item from the stack
char pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack underflow!\n");
        return '\0';
    }

    return stack->items[stack->top--];
}

// Function to check whether a character is an opening delimiter
bool isOpeningDelimiter(char ch) {
    return (ch == '(' || ch == '[' || ch == '{');
}

// Function to check whether a character is a closing delimiter
bool isClosingDelimiter(char ch) {
    return (ch == ')' || ch == ']' || ch == '}');
}

// Function to check whether two delimiters match
bool doDelimitersMatch(char opening, char closing) {
    if (opening == '(' && closing == ')')
        return true;
    if (opening == '[' && closing == ']')
        return true;
    if (opening == '{' && closing == '}')
        return true;
    return false;
}

// Function to check whether the expression is correct
bool isExpressionCorrect(const char* expression) {
    Stack stack;
    initializeStack(&stack);

    for (int i = 0; i < strlen(expression); i++) {
        if (isOpeningDelimiter(expression[i])) {
            push(&stack, expression[i]);
        } else if (isClosingDelimiter(expression[i])) {
            if (isStackEmpty(&stack) || !doDelimitersMatch(pop(&stack), expression[i])) {
                return false;
            }
        }
    }

    return isStackEmpty(&stack);
}

int main() {
    char expression[MAX_SIZE];

    printf("Enter an expression: ");
    fgets(expression, MAX_SIZE, stdin);

    // Remove the newline character from the input
    expression[strlen(expression) - 1] = '\0';

    if (isExpressionCorrect(expression)) {
        printf("The expression is correct.\n");
    } else {
        printf("The expression is incorrect.\n");
    }

    return 0;
}
