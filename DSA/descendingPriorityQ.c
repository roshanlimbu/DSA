#include <stdio.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
  int items[MAX];
  int rear;
  int size;
} PriorityQueue;

void initQueue(PriorityQueue *queue) {
  queue->rear = -1;
  queue->size = 0;
}

bool isFull(PriorityQueue *queue) { return queue->size == MAX; }

bool isEmpty(PriorityQueue *queue) { return queue->size == 0; }

void enqueue(PriorityQueue *queue, int item) {
  if (isFull(queue)) {
    printf("Priority queue is full!\n");
    return;
  }

  int i;
  for (i = queue->size - 1; i >= 0; i--) {
    // changed sign in ascending to greter than
    if (item > queue->items[i])
      queue->items[i + 1] = queue->items[i];
    else
      break;
  }

  queue->items[i + 1] = item;
  queue->size++;

  printf("Enqueued element: %d\n", item);
}

int dequeue(PriorityQueue *queue) {
  if (isEmpty(queue)) {
    printf("Priority queue is empty!\n");
    return -1;
  }

  int item = queue->items[queue->size - 1];
  queue->size--;

  return item;
}

void display(PriorityQueue *queue) {
  if (isEmpty(queue)) {
    printf("Priority queue is empty!\n");
    return;
  }

  printf("Priority queue:\n");

  for (int i = queue->size - 1; i >= 0; i--) {
    printf("%d ", queue->items[i]);
  }

  printf("\n");
}

int main() {
  PriorityQueue pq;
  initQueue(&pq);

  int choice, item;

  while (1) {
    printf("Priority Queue Application\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf_s("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter the element to enqueue: ");
      scanf_s("%d", &item);
      enqueue(&pq, item);
      break;

    case 2:
      item = dequeue(&pq);
      if (item != -1)
        printf("Dequeued element: %d\n", item);
      break;

    case 3:
      display(&pq);
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
