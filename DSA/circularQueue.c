#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#define MAX 10
#define TRUE 1
#define FALSE 0
struct queue {
  int front;
  int rear;
  int item[MAX];
};
int getNextPosition(int n) {
  if (n == MAX - 1) {
    return 0;
  } else {
    return n++;
  }
}
int isFull(struct queue q) {
  if (q.front == getNextPosition(q.rear)) {
    return TRUE;
  } else {
    return FALSE;
  }
}
int isEmpty(struct queue q) {
  // return q.form==q.rear;
  if (q.front == q.rear)
    return TRUE;
  else
    return FALSE;
}
void enqueue(struct queue *q, int n) {
  q->rear = getNextPosition(q->rear);
  q->item[q->rear] = n;
  printf("\nItem inserted.");
}
int dequeue(struct queue *q) {
  int n;
  q->front = getNextPosition(q->front);
  n = q->item[q->front];
  return n;
}
void display(struct queue q) {
  int i;
  if (isEmpty(q)) {
    printf("\nQueue underflow.");
  } else {
    printf("\nQueue contains: \n");
    i = q.front;
    do {
      i = getNextPosition(i);
      printf("%d\t", q.item[i]);
    } while (i != q.rear);
  }
}
int main() {
  int n;
  struct queue q;
  char choice;
  q.front = q.rear = MAX - 1;
  while (TRUE) {
    printf(
        "Select your choice : \n1. Enqueue \n2. Dequeue \n3. List \n4. Exit ");
    choice = getch();
    switch (choice) {
    case '1':
      if (isFull(q)) {
        printf("Can't add new items. \n");
      } else {
        printf("\nEnter a  number\n");
        scanf("%d", &n);
        enqueue(&q, n);
      }
      break;

    case '2':
      if (isEmpty(q)) {
        printf("\nqueue is empty.");
      } else {
        printf("\n %d has been removed from the queue.", dequeue(&q));
        break;
      }
    case '3':
      display(q);
      break;
    case '4':
      return (0);
      break;
    }
  }
}
