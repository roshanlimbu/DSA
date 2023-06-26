#include <conio.h>
#include <stdio.h>
#define MAX 10
struct priorityQ {
  int rear;
  int item[MAX];
} ;
int getSmallestPosition(priorityQ *q) {
  int pos = 0, i;
  for (i = 1; i <= q->rear; i++) {
    if (q->item[i] < q->item[pos])
      pos = i;
  }
  return pos;
}
int dequeue(priorityQ *q){
  int n, p, i;
  p=getSmallestPosition(q);
  n=q->item[p];
  for (i=p+1; i<=q->rear; i++){
    q->item [i-1]=q->item[i];
    q->rear--;
  }
  return;
}
