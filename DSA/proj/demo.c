#include <stdio.h>
#include <conio.h>
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
int main(){
  float amount;
  int units =0;
  int previousReading = 0;
  int currentReading = 0;
  printf("Enter the current meter reading: ");
  scanf_s("\n%d", &currentReading);
  units = currentReading -previousReading;
  amount = amountCalc(units);
  printf("%f", amount);
  printf("%d", units);
}
