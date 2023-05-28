#include <stdio.h>
#include <conio.h> 
int main(){
  int n, c=1, sum=0;
  printf("Enter the number: ");
  scanf("%d", &n);
  while (c<=n) {
    /* printf("%d", c); */
    sum+=c;
    c++;
  }
  printf("%d\n", sum); 
  return 0;
}
