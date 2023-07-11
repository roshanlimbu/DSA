// Electrictiy management system using c
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct {
  int customerId;
  int currentReading;
  int previousReading ;
  int meterId;
} ElectrictiyMeter;

typedef struct Node{
  int customerId;
  char name[50];
  char address[100];
  struct Node *next;
} Node;

int amountCalc(int x){
  int remainingUnit =0;
  float total = 0;
  if(x<0){
    printf("Invalid Data");
  } else{
    if(x==0){
      total = 30;
    } else if(x>0 && x<=20){ // 0-20
      total = 30 + x *3;


    } else if(x>=21 && x<=30){ // 21-30
      remainingUnit = x-20;
      total= 50+ 20*3 + remainingUnit * 7; 


    } else if(x>=31 && x<=50){ // 31-50
      remainingUnit = x-30;
      total = 75 + 20*3 + 10* 7 + remainingUnit * 8.5; 


    } else if(x>=51 && x<=150){ // 51-150
      remainingUnit = x-50;
      total = 100 + 20*3 + 10 * 7 + 20* 8.5 + remainingUnit * 10; 


    } else if(x>=151 && x<=250){  // 151-250
      remainingUnit = x-150;
      total = 125 + 20*3 + 10 * 7 + 20* 8.5 + 100 * 10 + remainingUnit * 11; 


    } else if(x>=251 && x<=400){ // 251 - 400
      remainingUnit = x-250;
      total = 150 + 20*3 + 10 * 7 + 20* 8.5 + 100 * 10 + 100 * 11 + remainingUnit * 12; 

    } else{
      remainingUnit = x- 400; // 400 and above
      total = 175 + 20*3 + 10 * 7 + 20* 8.5 + 100 * 10 + 100 * 11 + 150 * 12 + remainingUnit * 13;
    }
  }
  return total;
}


void calculateBill(ElectrictiyMeter  *meter){
  float amount;
  int units = meter->currentReading-meter->previousReading;
  // int previousReading = 0;
  // int currentReading = 0;
  // printf("Enter the current meter reading: ");
  // scanf_s_s("\n%d", &currentReading);
  // units = currentReading -previousReading;
  amount = amountCalc(units);
  printf("Customer Id: %d\n", meter->customerId);
  printf("Bill Amount: $%.2f\n", amount);
}
void displayCustomerInfo(Node *head){
  Node *ptrthis =head;
  while(ptrthis!=NULL){
    printf("Customer Id: %d\n", ptrthis->customerId);
    printf("Name: %s\n", ptrthis->name);
    printf("Address: %s\n", ptrthis->address);
    ptrthis = ptrthis->next;
  }
}
void addMeterReading(ElectrictiyMeter *meter){
  printf("Enter the current reading of meter ID %d: ", meter->meterId);
  scanf_s("%d", &meter->currentReading);
}
void addCustomer(Node *head){
  Node *newNode = (Node*)malloc(sizeof(Node));
  printf("Enter details for the new customer:\n");
  printf("Customer ID: ");
  scanf_s("%d", &newNode->customerId);
  printf("Name: ");
  scanf_s(" %[^\n]s", newNode->name);
  printf("Address: ");
  scanf_s(" %[^\n]s", newNode->address);


  newNode->next = head;
  head = newNode;
  printf("New Customer added Successfully.\n");

}
int main(){
  int choice;
  Node *customerList=NULL;
  int meterId=
}
