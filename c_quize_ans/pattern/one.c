#include <stdio.h>
#include <conio.h>
int main(){
  int a=0, b=1,  c=0, count=2;
  printf("%d %d", a, b);
  while (count<=8) {
    c=a+b; 
    printf("%d",c );
    count++;
    a=b;
    b=c;
  }
}
