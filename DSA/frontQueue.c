#include<stdio.h>
#include<process.h>
#define MAX 10
struct queue{
  int item[MAX];
  int rear;

};
void enqueue(struct queue *q , int val){
  if(q->rear == MAX-1){
    printf("Queue Overflow.");
    return;
  }
  // q->rear++;
  q->item[++q->rear]=val;
  printf("Item inserted successfully.");
  return;
}
int dequeue(struct queue *q){
  int val, i;
  if(q->rear == -1){
    printf("Queue underflow.");
    exit(0);
  } 
  val=q->item[0];
  for(i=1; i<=q->rear; i++){
    q->item[i-1]= q->item[i];
  }
    q->rear--;
    return val;

}

void display(struct queue q){
  int i;
  if(q.rear==-1){
    printf("Queue underflow.");
  } else {
    printf("\nQueue contains: ");
    for(i=0; i<=q.rear; i++){
      printf("%d\t", q.item[i]);
      printf("\n");
    }
  }
}
void main(){
  int n;
  char ch;
  struct queue q;
  system("cls");
  q.rear = -1; // empty queue initialized
  while(1){
    system("cls");
    printf("Select an option: \n1. Enqueue \n2. Dequeue \n3. Display \n4. Exit");
    ch=getche();
    switch(ch){
      case '1':
        printf("Enter a number: \n");
        scanf("%d", &n);
        enqueue(&q, n);
        break;
      case '2':
        if(q.rear==-1){
          printf("Queue underflow.");
        } else {
          n=dequeue(&q);
          printf("\n%d was removed",n);
        }
        break;
      case '3':
        display(q);
        break;
      case '4': return ;
    }
    getche();
  }

}
