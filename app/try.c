#include <stdio.h>
#include <conio.h>
#include <string.h>
#define maxStudent 100
typedef struct{
  int id; 
  char name[50]; 
  int roll;  
  char grade[1];
} studentInfo ;

void registerStudent(){
  studentInfo newStudent;
  printf("Enter the student id: ");
  scanf("%d", &newStudent.id);
  printf("Enter the student name: ");
  scanf("%s", newStudent.name);
  printf("Enter the student roll number: ");
  scanf("%d", &newStudent.roll);
  printf("Enter the student grade: ");
  scanf("%s", newStudent.grade);
}

void removeStudent(){}
void listStudent(){}
void modifyStudent(){}
int main(){
  int choice;
  while (1) {
    printf("1. Register new student.");
    printf("2. Remove student.");
    printf("3. list all student.");
    printf("4. Modify the list.");
    printf("5. Exit.");

    switch (choice) {
      case 1:
      registerStudent();
      break;
      case 2:
      removeStudent();
      break;
      case 3: 
      listStudent();
      break;
      case 4:
      modifyStudent();
      break;
      case 5: 
      exit(0);
      default:
      printf("Invalid choice\n");
    }
  }

}
