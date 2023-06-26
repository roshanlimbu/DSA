#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 10 

struct queue{
    int item[MAX];
    int rear;
};

void enqueue(struct queue*q, int val){
    if(q->rear == MAX-1){
        printf("queue overflow! you cannot insert more items");
    }

    q->rear++;
    q->item[q->rear]=val;
    printf(" item inserted sucessfully ");
    return;
};

int dequeue(struct queue*q){
    int val, i;
    if(q->rear==-1){
        printf(" queue is empty, you cannot remove ");
        exit(0);
    }
    val=q->item[0];
    for (i = 0; i < q->rear; i++)
    {
        q->item[i-1]=q->item[i];
    }
    q->rear--;
    return val;
}

void display(struct queue q){
    int i;
    if(q.rear==-1){
        printf(" queue is empty ");
        getch();

    }else{
        printf("\n queue contains \n");
        for (i = 0; i <=q.rear; i++)
        {
            printf(" %d \t ", q.item[i]);
        }
        getch();
    }
}

void main(){
    struct queue q;
    char ch;
    int n;
    q.rear=-1;  // empty queue 
    while(1){
        system("CLS");
        printf("select an option:\n 1. Enqueue \n 2. Dequeue\n 3. Display \n 4. End \n");
        ch=getche();
        switch (ch)
        {
            case '1':
                printf(" Enter a number ");
                scanf("%d", &n);
                enqueue(&q, n);
            break;

            case '2':
                if(q.rear == -1){
                    printf("queue is empty");
                    getch();
                }else{
                    n=dequeue(&q);
                    printf("%d was removed");
                    getch();
                }
                break;
            case '3':
                display(q);
            break;
            case '4':
                return;
            break;
        }
    }
    getch();
}
