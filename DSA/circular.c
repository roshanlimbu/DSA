#include <stdbool.h>
#include <stdio.h>

#define MAX_CAPACITY 10 

typedef struct {
  int items[MAX_CAPACITY];
  int front;
  int rear;
  int size;
} CircularQueue;

void initQueue(CircularQueue *queue) {
  queue->front = -1;
  queue->rear = -1;
  queue->size = 0;
}

bool isFull(CircularQueue *queue) {
  return (queue->front == 0 && queue->rear == MAX_CAPACITY - 1) ||
         (queue->front == queue->rear + 1);
}

bool isEmpty(CircularQueue *queue) { return queue->front == -1; }

void enqueue(CircularQueue *queue, int item) {
  if (isFull(queue)) {
    printf("Circular queue is full!\n");
    return;
  }

  if (queue->front == -1)
    queue->front = 0;

  queue->rear = (queue->rear + 1) % MAX_CAPACITY;
  queue->items[queue->rear] = item;
  queue->size++;

  printf("Enqueued element: %d\n", item);
}

int dequeue(CircularQueue *queue) {
  if (isEmpty(queue)) {
    printf("Circular queue is empty!\n");
    return -1;
  }

  int item = queue->items[queue->front];
  queue->size--;

  if (queue->front == queue->rear) {
    queue->front = -1;
    queue->rear = -1;
  } else {
    queue->front = (queue->front + 1) % MAX_CAPACITY;
  }

  return item;
}

void display(CircularQueue *queue) {
  if (isEmpty(queue)) {
    printf("Circular queue is empty!\n");
    return;
  }

  printf("Circular queue:\n");

  int i = queue->front;
  while (i != queue->rear) {
    printf("%d ", queue->items[i]);
    i = (i + 1) % MAX_CAPACITY;
  }

  printf("%d\n", queue->items[i]);
}

int main() {
  CircularQueue cq;
  initQueue(&cq);

  int choice, item;

  while (1) {
    printf("Circular Queue Application\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter the element to enqueue: ");
      scanf("%d", &item);
      enqueue(&cq, item);
      break;

    case 2:
      item = dequeue(&cq);
      if (item != -1)
        printf("Dequeued element: %d\n", item);
      break;

    case 3:
      display(&cq);
      break;

    case 4:
      printf("Exiting the program.\n");
      return 0;

    default:
      printf("Invalid choice! Please enter a valid option.\n");
    }

    printf("\n");
  }

  return 0;
}
