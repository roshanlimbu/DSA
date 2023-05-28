#include <stdio.h>
#include <conio.h>
#include <math.h>
int main(){
  int i, n, digitCount, sum;
  for(i=1; i<=200000; i++)
    {
    n=i;
    digitCount=0;
      while (n>0) {
     n=n/10;
     digitCount++;//  100 3
      }
    n=i;
    sum=0;
    while (n>0) {
    sum= sum+ pow(n%10, digitCount); 
      n=n/10;
    }
    if (sum==i) {
   printf("%d\n", sum); 
    }
    }
}
