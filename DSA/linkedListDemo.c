#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node **head, int data) {
  Node *newNode = createNode(data);
  newNode->next = *head;
  *head = newNode;
}

// Function to display the linked list
void displayList(Node *head) {
  Node *current = head;
  if (current == NULL) {
    printf("List is empty.\n");
    return;
  }

  printf("Linked List: ");
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  Node *head = NULL; // Initialize an empty list

  // Insert nodes at the beginning
  insertAtBeginning(&head, 5);
  insertAtBeginning(&head, 10);
  insertAtBeginning(&head, 15);

  // Display the linked list
  displayList(head);

  return 0;
}
