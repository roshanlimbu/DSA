#include <stdio.h>
#include <stdlib.h>

// Define the structure for each node in the linked list
struct Node {
  int data;
  struct Node *next;
};

// Function to insert data at the end of the linked list
void insert(struct Node **head, int data) {
  // Create a new node
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  // If the linked list is empty, make the new node as the head
  if (*head == NULL) {
    *head = newNode;
  } else {
    // Traverse to the last node and insert the new node
    struct Node *temp = *head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
  printf("Data inserted successfully.\n");
}

// Function to remove data from the linked list
void removeData(struct Node **head, int data) {
  // If the linked list is empty, return
  if (*head == NULL) {
    printf("Linked list is empty.\n");
    return;
  }

  // If the head node needs to be removed
  if ((*head)->data == data) {
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Data removed successfully.\n");
    return;
  }

  // Traverse the linked list to find the node to remove
  struct Node *prev = *head;
  struct Node *curr = (*head)->next;
  while (curr != NULL && curr->data != data) {
    prev = curr;
    curr = curr->next;
  }

  // If the node is found, remove it
  if (curr != NULL) {
    prev->next = curr->next;
    free(curr);
    printf("Data removed successfully.\n");
  } else {
    printf("Data not found in the linked list.\n");
  }
}

// Function to display the data in the linked list
void display(struct Node *head) {
  // If the linked list is empty, return
  if (head == NULL) {
    printf("Linked list is empty.\n");
    return;
  }

  printf("Linked list data: ");
  struct Node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  struct Node *head = NULL;
  int choice, data;

  while (1) {
    printf("\nLinked List Operations:\n");
    printf("1. Insert data at the end\n");
    printf("2. Remove data\n");
    printf("3. Display data\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter data to insert: ");
      scanf("%d", &data);
      insert(&head, data);
      break;
    case 2:
      printf("Enter data to remove: ");
      scanf("%d", &data);
      removeData(&head, data);
      break;
    case 3:
      display(head);
      break;
    case 4:
      printf("Exiting...\n");
      exit(0);
    default:
      printf("Invalid choice! Please enter a valid option.\n");
    }
  }
}
