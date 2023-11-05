// Design, Develop and Implement a menu driven Program in C for the following 
// operations on Doubly Linked List (DLL) of Employee Data with the fields: 
// SSN, Name, Dept, Designation, Sal, PhNo
// a. Create a DLL of N Employees Data by using end insertion.
// b. Display the status of DLL and count the number of nodes in it
// c. Perform Insertion and Deletion at End of DLL
// d. Perform Insertion and Deletion at Front of DLL
// e. Demonstrate how this DLL can be used as Double Ended Queue
// f. Exit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee {
    char ssn[11];
    char name[50];
    char dept[50];
    char designation[50];
    float sal;
    char phNo[11];
    struct Employee* next;
    struct Employee* prev;
} Employee;

Employee* head = NULL;

Employee* createEmployee() {
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    printf("Enter SSN, Name, Dept, Designation, Sal, PhNo: ");
    scanf("%s %s %s %s %f %s", newEmployee->ssn, newEmployee->name, newEmployee->dept, newEmployee->designation, &(newEmployee->sal), newEmployee->phNo);
    newEmployee->next = NULL;
    newEmployee->prev = NULL;
    return newEmployee;
}

void insertEnd() {
    Employee* newEmployee = createEmployee();
    if (head == NULL) {
        head = newEmployee;
    } else {
        Employee* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newEmployee;
        newEmployee->prev = temp;
    }
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        Employee* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
}

void insertFront() {
    Employee* newEmployee = createEmployee();
    if (head == NULL) {
        head = newEmployee;
    } else {
        newEmployee->next = head;
        head->prev = newEmployee;
        head = newEmployee;
    }
}

void deleteFront() {
    if (head == NULL) {
        printf("List is empty\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        Employee* temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        Employee* temp = head;
        while (temp != NULL) {
            printf("%s %s %s %s %.2f %s\n", temp->ssn, temp->name, temp->dept, temp->designation, temp->sal, temp->phNo);
            temp = temp->next;
        }
    }
}

int countNodes() {
    int count = 0;
    Employee* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Insert End\n2. Delete End\n3. Insert Front\n4. Delete Front\n5. Display\n6. Count Nodes\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
              insertEnd();
              break;
            case 2: 
              deleteEnd(); 
              break;
            case 3: 
              insertFront(); 
              break;
            case 4: 
              deleteFront(); 
              break;
            case 5: 
              display(); 
              break;
            case 6: 
              printf("Number of nodes: %d\n", countNodes()); 
              break;
            case 7: 
              exit(0);
            default: 
              printf("Invalid choice\n");
        }
    }
    return 0;
}