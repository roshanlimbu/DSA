#include <stdio.h>
#include <process.h>
void gotoxy(int x,int y)
{
printf("%c[%d;%df",0x1B,y,x);
}
int main ()

{
  system("cls");
gotoxy(25,50); //reposition cursor
printf("hello world"); //display text
}
