#include <stdio.h>
#include <stdlib.h>

struct Customer {
    int id;
    char name[50];
    int meterId;
    int prevMeterReading;
    int currMeterReading;
    struct Customer* next;
};

struct Customer* head = NULL;

void addCustomer() {
    struct Customer* newCustomer = (struct Customer*)malloc(sizeof(struct Customer));

    printf("Enter customer ID: ");
    scanf_s("%d", &newCustomer->id);

    printf("Enter customer name: ");
    scanf_s("%s", newCustomer->name);

    printf("Enter meter ID: ");
    scanf_s("%d", &newCustomer->meterId);

    printf("Enter previous meter reading: ");
    scanf_s("%d", &newCustomer->prevMeterReading);

    printf("Enter current meter reading: ");
    scanf_s("%d", &newCustomer->currMeterReading);

    newCustomer->next = NULL;

    if (head == NULL) {
        head = newCustomer;
    } else {
        struct Customer* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newCustomer;
    }

    printf("Customer added successfully.\n");
}

void modifyCustomer() {
    int id;

    printf("Enter customer ID to modify: ");
    scanf_s("%d", &id);

    struct Customer* current = head;
    while (current != NULL) {
        if (current->id == id) {
            printf("Enter modified customer name: ");
            scanf_s("%s", current->name);

            printf("Enter modified meter ID: ");
            scanf_s("%d", &current->meterId);

            printf("Enter modified previous meter reading: ");
            scanf_s("%d", &current->prevMeterReading);

            printf("Enter modified current meter reading: ");
            scanf_s("%d", &current->currMeterReading);

            printf("Customer modified successfully.\n");
            return;
        }
        current = current->next;
    }

    printf("Customer with ID %d not found.\n", id);
}

int calculateUnitsConsumed (struct Customer *customer){
  return customer->currMeterReading-customer->prevMeterReading;
}

float calculateAmount(struct Customer *customer){
  int unitsConsumed = calculateUnitsConsumed(customer);
  int remainingUnit = 0;
  float total =0;
  if(unitsConsumed==0){
    total = 30;
  } else if(unitsConsumed>0 && unitsConsumed<=20){
    total = 30 + unitsConsumed*3;
  } else if(unitsConsumed >=21 && unitsConsumed<=30){
    remainingUnit = unitsConsumed -20;
    total = 50 + 20*3 + remainingUnit *7;
  } else if(unitsConsumed>=31 && unitsConsumed<=50){ // 31-50
      remainingUnit = unitsConsumed-30;
      total = 75 + 20*3 + 10* 7 + remainingUnit * 8.5; 
  } else if(unitsConsumed>=51 && unitsConsumed<=150){ // 51-150
      remainingUnit = unitsConsumed-50;
      total = 100 + 20*3 + 10 * 7 + 20* 8.5 + remainingUnit * 10; 
  } else if(unitsConsumed>=151 && unitsConsumed<=250){  // 151-250
      remainingUnit = unitsConsumed-150;
      total = 125 + 20*3 + 10 * 7 + 20* 8.5 + 100 * 10 + remainingUnit * 11; 
  } else if(unitsConsumed>=251 && unitsConsumed<=400){ // 251 - 400
      remainingUnit = unitsConsumed-250;
      total = 150 + 20*3 + 10 * 7 + 20* 8.5 + 100 * 10 + 100 * 11 + remainingUnit * 12; 
  } else{
      remainingUnit = remainingUnit- 400; // 400 and above
      total = 175 + 20*3 + 10 * 7 + 20* 8.5 + 100 * 10 + 100 * 11 + 150 * 12 + remainingUnit * 13;
  }
  return total;
} 

void displayCustomers() {
    printf("Customer Details:\n");

    struct Customer* current = head;
    while (current != NULL) {
        printf("ID: %d\n", current->id);
        printf("Name: %s\n", current->name);
        printf("Meter ID: %d\n", current->meterId);
        printf("Previous Meter Reading: %d\n", current->prevMeterReading);
        printf("Current Meter Reading: %d\n", current->currMeterReading);
        int unitsConsumed = calculateUnitsConsumed(current);
        printf("Units Consumed: %d\n", unitsConsumed);
        int amountTopay = calculateAmount(current);
        printf("Amount to pay: $%d\n", amountTopay);
        printf("------------------------------\n");
        current = current->next;
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Add Customer\n");
        printf("2. Modify Customer\n");
        printf("3. Display Customers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice);

        switch (choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                modifyCustomer();
                break;
            case 3:
                displayCustomers();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
