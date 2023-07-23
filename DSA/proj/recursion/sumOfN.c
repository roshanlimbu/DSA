// WAp to calculate the sum of first n natural numbers using recursion

#include <stdio.h>
#include <conio.h>
int sum(int n){
  if(n==0){
    return 0;
  } else {
    return n+sum(n-1);
  }
}
int main(){
  int n;
  printf("Enter the value of n: ");
  scanf_s("%d", &n);
  printf("%d", sum(n));
}
