#include <stdio.h>
#include <conio.h>
int main(){
  int n, i, fact=1;
  printf("Enter the nubmer");
  scanf("%d", &n);
  for (i=1; i<=n; i++) { 
    fact*=i;
  }
  printf("%d", fact); 
}
