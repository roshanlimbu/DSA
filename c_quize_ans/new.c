/* WAP a program to generate the following pattern
 1 2 3 4 5
 1 2 3 4 5
 1 2 3 4 5
 1 2 3 4 5
 1 2 3 4 5
*/
/*
#include <stdio.h>
#include <conio.h>
int main(){
  int i, j;
  for (i=1; i<=5; i++){
    for (j=1; j<=5; j++){
      printf(" %d", j);
    }
    printf("\n");
  }
}
*/
/* WAP to generate the following pattern
 1 1 1 1 1
 2 2 2 2 2
 3 3 3 3 3
 4 4 4 4 4
 5 5 5 5 5
*/
/*
#include <stdio.h>
#include <conio.h>
int main(){
  int i, j;
  for (i=1; i<=5; i++){
    for (j=1; j<=5; j++){
      printf(" %d", i);
    }
    printf("\n");
  }
}
*/
/* WAP to generate the following pattern
 * * * * *
 * * * * *
 * * * * *
 * * * * *
 * * * * *
*/

/*
#include <stdio.h>
#include <conio.h>
int main(){
  int i, j;
  for (i=1; i<=5; i++){
    for (j=1; j<=5; j++){
      printf(" *");
    }
    printf("\n");
  }
}
*/

/* WAP to generate the following pattern
 A B C D E
 A B C D E
 A B C D E
 A B C D E
 A B C D E

*/
/*
#include <stdio.h>
#include <conio.h>
int main(){
  int i, j;
  for (i=1; i<=5; i++){
      printf(" A B C D E");
    printf("\n");
  }
}
*/
/* WAP to generate the following pattern 
1 
1 2 
1 2 3 
1 2 3 4
1 2 3 4 5 
*/

/*
#include <stdio.h>
#include <conio.h>
int main(){
  int i, j;
  for (i=1; i<=5; i++){
  for (j=1; j<=i; j++){
    printf("%d", j);
         }
    printf("\n");
  }
}
*/
/*
 *
 * *
 * * *
 * * * *
 * * * * *
*/
/*
#include <stdio.h>
#include <conio.h>
int main(){
  int a, b;
  for (a=1; a<=5; a++) {
  for (b=1; b<=a; b++) {
    printf(" *");
    }
  printf("\n");
  }
}
*/

/* #include <stdio.h> */
/* #include <conio.h> */
/* int main(){ */
/*   int i, j; */ 
/*   for (i=5; i>=1; i--) { */
/*     for (j=1; j<=i; j++) { */
/*    printf("%d", i); */ 
/*     } */
/*   } */
/*   printf("\n"); */
/*   } */
#include <stdio.h>
#include <conio.h>
int main(){
  int a=1, b=100, count=0;
  for (b; b<200 ; b++) {
    while (a<=b) {
   if (b % a == 0) {
        count ++; 
        a++;
   } 
   if(count== 2 ){
      printf("%d", b);
      }
    }
  }
  return 0;
}
