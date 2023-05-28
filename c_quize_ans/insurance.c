#include <stdio.h>
#include <conio.h>
int main(){
  int age;
  char gender ;
  char marital;
  printf("Are you married: Y/N ");
  scanf("%c", &marital);
  // or use martial = getche();
  fflush(stdin);
  printf("Are you male or female M/F\n");
  printf("Enter your age: ");
  scanf("%d", &age);
  fflush(stdin);
  printf("Are you male or female M/F\n");
  scanf("%c", &gender);
  // or use gender = getche();
  fflush(stdin);
  printf("Are you male or female M/F\n");
    if (marital == 'Y') {
   printf("You're insured. "); 
    } else if (age>30 && marital == 'U' && gender == 'M') {
 printf("Enter you're insured. "); 
    } else if (age>25 && marital == 'U' && gender == 'F'){
    printf("You're insured. ");
  } else {
  printf("You're not insured.");
  }
  return 0;
}

