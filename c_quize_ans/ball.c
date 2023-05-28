#include <stdio.h>
#include <conio.h>
int main(){
float  height, count;
  printf("Enter the initial height:"); // input height
  scanf("%f", &height); // assigning value
  for (count=0; height>0.2; count++){ // looping through the height until it reaches 0.2
  height=height*0.8;
  }
  printf("%f", count);
return 0;
}
