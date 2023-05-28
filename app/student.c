#include <stdio.h>
#include <conio.h>
#define MAX 100
struct student {
  int id; 
  char name[50];
  int roll;
  char phone[100];
  char grade[20];
};
struct student list [MAX];
int counter=0;
void addStudent(){
  printf("Welcome to student Registration Part: ");
  printf("\n Enter your Id: ");
  scanf("%d", &list[counter].id);
  printf("\nEnter your name");
  gets(list[counter].name);
  printf("\nEnter your roll number: ");
  scanf("%d", &list[counter].roll);
  printf("\nEnter your phone number");
  scanf("%d",list[counter].phone);j
  fflush(stdin);
  printf("\nEnter your grade");
  gets(list[counter].grade);
  counter++;
  printf("\n\nRegistration successful");
}
void removeStudent(){
}
void editStudent(){

}
void listStudent(){
  int i;
  if (counter==0){
    printf("list is empty.");
  }else {
    printf("list of Students.\n");
    printf("Id\tName of student\tRoll No.\tPhone No. \t Grade \n");
    for(i=0;i<counter; i++){
      printf("%d\t%s\t%d\t%d\t%s");
    }
  }

}
void saveStudent(){
  FILE *fp;
}
