#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int id;
    char name[50];
    int roll;
    int class;
    /* char grade; */
} Student;

Student studentRegister[MAX_STUDENTS];
int numStudents = 0;

void registerStudent() {
    if (numStudents == MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }

    Student newStudent;
    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);
    fflush(stdin); 
    printf("Enter student name: ");
    scanf("%s", newStudent.name);
    printf("Enter student roll: ");
    scanf("%d", &newStudent.roll);
    printf("Enter student class: ");
    scanf("%d", &newStudent.class);
    /* printf("Enter student grade: "); */
    /* scanf("%s", newStudent.grade); */

    studentRegister[numStudents++] = newStudent;

    printf("Student registered successfully.\n");
}

void modifyRegister() {
    int id, i;
    printf("Enter the student ID to modify: ");
    scanf("%d", &id);

    for (i = 0; i < numStudents; i++) {
        if (studentRegister[i].id == id) {
            printf("Enter modified student name: ");
            scanf("%s", studentRegister[i].name);
            printf("Enter modified student roll: ");
            scanf("%d", &studentRegister[i].roll);
            printf("Enter modified student class: ");
            scanf("%d", &studentRegister[i].class);

            printf("Student record modified successfully.\n");
            return;
        }
    }

    printf("Student with ID %d not found.\n", id);
}

void removeStudent() {
    int id, i, j;
    printf("Enter the student ID to remove: ");
    scanf("%d", &id);

    for (i = 0; i < numStudents; i++) {
        if (studentRegister[i].id == id) {
            for (j = i; j < numStudents - 1; j++) {
                studentRegister[j] = studentRegister[j + 1];
            }

            numStudents--;
            printf("Student removed successfully.\n");
            return;
        } else {
            printf("Student with ID %d not found.\n", id);
        }
    }

}

void listStudents() {
    if (numStudents == 0) {
        printf("No students registered.\n");
        return;
    }

    printf("Registered students:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("ID: %d, Name: %s, Roll: %d, Class: %d\n",
               studentRegister[i].id, studentRegister[i].name,
               studentRegister[i].roll, studentRegister[i].class);
    }
}

void searchStudent() {
    /* char searchName[50]; */
    int intId;
    int found = 0;

    printf("Enter student id to search:  ");
    scanf("%d", &intId);

    printf("Matching students:\n");
    for (int i = 0; i < numStudents; i++) {
        if (studentRegister[i].id, searchName) == 0 &&
            studentRegister[i].roll == searchRoll &&
            studentRegister[i].class == searchClass) {
            printf("ID: %d, Name: %s, Roll: %d, Class: %d\n",
                   studentRegister[i].id, studentRegister[i].name,
                   studentRegister[i].roll, studentRegister[i].class);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching students found.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nStudent Register\n");
        printf("1. Register a new student\n");
        printf("2. Modify a student record based on ID\n");
        printf("3. Remove a student based on ID\n");
        printf("4. List all students\n");
        printf("5. Search a student by name, roll, and class\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerStudent();
                break;
            case 2:
                modifyRegister();
                break;
            case 3:
                removeStudent();
                break;
            case 4:
                listStudents();
                break;
            case 5:
                searchStudent();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

