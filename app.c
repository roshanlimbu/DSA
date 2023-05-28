#include <stdio.h>
#include <conio.h>
int main(){ 
  int age, result;
  printf("Enter your age: ");
  scanf("%d\n",&age );
  vote(age);
}
int vote(int a){
  if (a>18){
    printf("%d\n",1);
  } else{
    printf("%d\n",0);
  }
}
