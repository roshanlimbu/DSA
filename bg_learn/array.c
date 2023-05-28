#include <stdio.h>
#include <conio.h>
int main(){
  int age[5];
  for (int i=0; i<5; i++){
    printf("Enter the age");
    scanf("%d", &age[i]);
  }
  printf("%d", age[0]);
}
