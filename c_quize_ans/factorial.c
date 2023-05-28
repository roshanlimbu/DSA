#include <stdio.h>
#include <conio.h>
int main ()
{
 int i, num, factorial=1; 
  printf("Enter the number to find factorial: ");
  scanf("%d", &num);
  for (i=1;  i<=num; i++) {
    factorial=factorial*i;
  }
    printf("%d\n", factorial);
  return 0;
} 
