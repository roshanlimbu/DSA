#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
  char username[30];
  int id;
  int salary;
  struct Node *next;
};

struct Node *head = NULL;

void addNode(char *username, int id, int salary) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  strcpy(newNode->username, username);
  newNode->id = id;
  newNode->salary = salary;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    struct Node *currentNode = head;
    while (currentNode->next != NULL) {
      currentNode = currentNode->next;
    }
    currentNode->next = newNode;
  }
}

void printList() {
  struct Node *currentNode = head;
  while (currentNode != NULL) {
    printf("Username: %s\nID: %d\nSalary: %d\n", currentNode->username, currentNode->id, currentNode->salary);
    printf("Do you want to add another employee? (y/n)\n");
    char response;
    scanf("%c", &response);
    if (response == 'y') {
      char username[30];
      int id;
      int salary;
      printf("Enter username: ");
      scanf("%s", username);
      printf("Enter id: ");
      scanf("%d", &id);
      printf("Enter salary: ");
      scanf("%d", &salary);
      addNode(username, id, salary);
    } else {
      break;
    }
    currentNode = currentNode->next;
  }
}

int main() {
  printf("Welcome to the employee management system.\n");
  printList();
  printf("Thank you for using the employee management system.\n");
  return 0;
}

