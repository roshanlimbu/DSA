#include <stdio.h>
#include <process.h>
#include <conio.h>
#define TRUE 1 
#define FALSE  
#define UP 75
#define DOWN 77
#define ENTER 12 
void gotoxy(int x,int y){
    printf("%c[%d;%df",0x1B,y,x);
}
int main(){
  char choice;
  int selected= 1;
  while(TRUE){
    gotoxy(10, 12);
    printf("Select your choice.");
    system("cls");
    gotoxy(10, 13);
    if(selected==1){
      printf("[X] Register");
    } else {
    printf("[ ] Register");
    }
    system("cls");
    gotoxy(10, 14);
    if (selected==2) {
      printf("[X] Remove"); 
    } else {
      printf("[ ] Remove");
    }
    system("cls");
    gotoxy(10, 15);
    if (selected==3) {
      printf("[X] List");
    } else {
      printf("[ ] List");
    }
    system("cls");
    gotoxy(10, 16);
    if (selected==4) {
      printf("[X] Exit");
    } else{
      printf("[X] Exit");
    }
    fflush(stdin);
    choice=getche();
    switch (choice) {
      case UP: 
      if (selected>1) {
          selected--;
          break;
      }
      case DOWN:
      if (selected<4) {
          selected++;
          break;
      }
      case ENTER:
      switch (selected) {
          case 1:
          printf("Exit Register function\n");
          break;

          case 2: 
          printf("Exit Remove function");
          break;

          case 3: 
          printf("Exit list function.");
      }
    }
  }
}
