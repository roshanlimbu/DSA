#include <stdio.h>
#include <conio.h>
void toh(int n, char s, char i , char d){
  if (n>0){
    toh(n-1, s, d, i);
    printf("\nMove %dth disk from %c to %c", n, s,d);
    toh(n-1, i, s, d);
    }

  };
int main(){
  int n; 
  printf("How many disks?\n");
  scanf_s("%d", &n);
  toh(n,'S', 'I', 'D' );
  _getch();
}
