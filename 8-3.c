// Design, Develop and Implement a menu driven Program in C for the following 
// operations on Single Circular Linked List (SCLL) of Employee Data with the 
// fields: SSN, Name, Dept, Designation, Sal, PhNo
// a. Create a SCLL of N Employees Data by using end insertion.
// b. Display the status of SCLL and count the number of nodes in it
// c. Perform Insertion and Deletion at End of SCLL
// d. Perform Insertion and Deletion at Front of SCLL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee {
    char ssn[11];
    char name[100];
    char dept[50];
    char designation[50];
    float sal;
    char phNo[11];
    struct Employee *next;
} Employee;

Employee *last = NULL;

Employee* createEmployee() {
    Employee *newEmployee = (Employee*)malloc(sizeof(Employee));
    printf("Enter SSN: ");
    scanf("%s", newEmployee->ssn);
    printf("Enter Name: ");
    scanf("%s", newEmployee->name);
    printf("Enter Department: ");
    scanf("%s", newEmployee->dept);
    printf("Enter Designation: ");
    scanf("%s", newEmployee->designation);
    printf("Enter Salary: ");
    scanf("%f", &(newEmployee->sal));
    printf("Enter Phone Number: ");
    scanf("%s", newEmployee->phNo);
    newEmployee->next = NULL;
    return newEmployee;
}

void insertEnd() {
    Employee *newEmployee = createEmployee();
    if (last == NULL) {
        last = newEmployee;
        last->next = last;
    } else {
        newEmployee->next = last->next;
        last->next = newEmployee;
        last = newEmployee;
    }
}

void insertFront() {
    Employee *newEmployee = createEmployee();
    if (last == NULL) {
        last = newEmployee;
        last->next = last;
    } else {
        newEmployee->next = last->next;
        last->next = newEmployee;
    }
}

void deleteEnd() {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    Employee *temp = last->next;
    while (temp->next != last) {
        temp = temp->next;
    }
    temp->next = last->next;
    free(last);
    last = temp;
}

void deleteFront() {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    Employee *temp = last->next;
    last->next = temp->next;
    free(temp);
}

void display() {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    Employee *temp = last->next;
    do {
        printf("SSN: %s, Name: %s, Department: %s, Designation: %s, Salary: %.2f, Phone Number: %s\n", temp->ssn, temp->name, temp->dept, temp->designation, temp->sal, temp->phNo);
        temp = temp->next;
    } while (temp != last->next);
}

int main() {
    int choice;
    while (1) {
        printf("1. Insert End\n2. Insert Front\n3. Delete End\n4. Delete Front\n5. Display\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
              insertEnd();
              break;
            case 2: 
              insertFront();
              break;
            case 3:
              deleteEnd();
              break;
            case 4: 
              deleteFront();
              break;
            case 5: 
              display();
              break;
            case 6: 
              exit(0);
            default: 
              printf("Invalid choice\n");
        }
    }
    return 0;
}