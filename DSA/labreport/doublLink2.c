#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

typedef struct Node Node;

struct DoublyLinkedList {
    Node* head;
};

typedef struct DoublyLinkedList DoublyLinkedList;

void insertAtFront(DoublyLinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = list->head;

    if (list->head != NULL) {
        list->head->prev = newNode;
    }

    list->head = newNode;
}

void insertAtLast(DoublyLinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        newNode->prev = NULL;
        list->head = newNode;
        return;
    }

    Node* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

void displayList(DoublyLinkedList* list) {
    Node* current = list->head;
    if (current == NULL) {
        printf("Doubly Linked List is empty.\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    DoublyLinkedList list;
    list.head = NULL;

    int choice, data;

    while (1) {
        printf("1. Insert at Front\n");
        printf("2. Insert at Last\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert at front: ");
                scanf("%d", &data);
                insertAtFront(&list, data);
                printf("Element inserted at the front.\n");
                break;
            case 2:
                printf("Enter the data to insert at last: ");
                scanf("%d", &data);
                insertAtLast(&list, data);
                printf("Element inserted at the last.\n");
                break;
            case 3:
                displayList(&list);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}
