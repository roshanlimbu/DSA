#include <stdio.h>
#include <conio.h>
int main(){
  int unit ;
  float total=0;
  printf("Enter your consumed unit: ");
  scanf("%d", &unit);
  if (unit<=20) {
    total = 80;
  } else if (unit>20 && unit<=200) {
    total=  80 + (unit-20)*7.5;
  } else if (unit>200) {
   total = 80 + (unit-20)*7.5 + (unit-200)*10;
  }
   printf("%fYour Electricity charge is Rs. ", total);
  return 0;
}
