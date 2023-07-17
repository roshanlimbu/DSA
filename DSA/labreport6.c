#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct queue {
    int item[MAX];
    int rear;
    int front;
};

typedef struct queue qu;

void insert(qu*);
void delet(qu*);
void display(qu*);

int main() {
    int ch;
    qu q; // Declare the queue variable, not a pointer
    q.rear = -1;
    q.front = 0;

    printf("Menu for program: \n");
    printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf_s("%d", &ch);

        switch (ch) {
        case 1:
            insert(&q); // Pass the address of the queue
            break;
        case 2:
            delet(&q); // Pass the address of the queue
            break;
        case 3:
            display(&q); // Pass the address of the queue
            break;
        case 4:
            exit(0); // Use exit(0) instead of exit(1) to indicate successful program termination
        default:
            printf("Your choice is wrong.\n");
        }
    } while (1);

    return 0;
}

void insert(qu* q) {
    int d;
    printf("Enter data to be inserted: ");
    scanf_s("%d", &d);
    if (q->rear == MAX - 1) {
        printf("Queue is full.\n");
    }
    else {
        q->rear++;
        q->item[q->rear] = d;
    }
}

void delet(qu* q) {
    int d;
    if (q->rear < q->front) {
        printf("Queue is empty.\n");
    }
    else {
        d = q->item[q->front];
        q->front++;
        printf("Deleted item is: %d\n", d);
    }
}

void display(qu* q) {
    int i;
    if (q->rear < q->front) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Queue: ");
        for (i = q->front; i <= q->rear; i++) {
            printf("%d\t", q->item[i]);
        }
        printf("\n");
    }
}

