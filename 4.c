// Design, Develop and Implement a menu driven Program in C for the following 
// operations on Singly Linked List (SLL) of Student Data with the fields: USN, 
// Name, Branch, Sem, PhNo
// a. Create a SLL of N Students Data by using front insertion.
// b. Display the status of SLL and count the number of nodes in it
// c. Perform Insertion / Deletion at End of SLL
// d. Perform Insertion / Deletion at Front of SLL(Demonstration of stack)
// e. Exit
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  int USN;
  char Name[20];
  char Branch[20];
  int Sem;
  char phNo[10];
  struct Node* next;
} *head;

void createList(int n) {
  int i, USN, Sem;
  char Name[20], Branch[20], phNo[10];

  struct Node *newNode, *temp;

  for (i = 0; i < n; i++) {
    printf("Enter the USN, Name, Branch, Sem, and Phone Number of student %d: ", i + 1);
    scanf("%d %s %s %d %s", &USN, Name, Branch, &Sem, phNo);

    newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->USN = USN;
    strcpy(newNode->Name, Name);
    strcpy(newNode->Branch, Branch);
    newNode->Sem = Sem;
    strcpy(newNode->phNo, phNo);

    newNode->next = NULL;

    if (head == NULL) {
      head = newNode;
    } else {
      temp = head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = newNode;
    }
  }

  printf("List created successfully\n");
}

void displayList() {
  struct Node *p;

  if (head == NULL) {
    printf("List is empty\n");
    return;
  }
  printf("List of students:\n");
  p = head;
  while (p != NULL) {
    printf("USN: %d\n", p->USN);
    printf("Name: %s\n", p->Name);
    printf("Branch: %s\n", p->Branch);
    printf("Sem: %d\n", p->Sem);
    printf("Phone Number: %s\n", p->phNo);
    printf("\n");

    p = p->next;
  }
}

void insertEnd(int USN, char Name[], char Branch[], int Sem, char phNo[]) {
  struct Node *newNode, *temp;

  newNode = (struct Node*) malloc(sizeof(struct Node));

  newNode->USN = USN;
  strcpy(newNode->Name, Name);
  strcpy(newNode->Branch, Branch);
  newNode->Sem = Sem;
  strcpy(newNode->phNo, phNo);

  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  printf("Student inserted at the end successfully\n");
}

void deleteEnd() {
  struct Node *prev, *temp;

  if (head == NULL) {
    printf("List is empty\n");
    return;
  }

  if (head->next == NULL) {
    free(head);
    head = NULL;
    printf("Student deleted from the end successfully\n");
    return;
  }

  prev = NULL;
  temp = head;
  while (temp->next != NULL) {
    prev = temp;
    temp = temp->next;
  }
  prev->next = NULL;
  free(temp);

  printf("Student deleted from the end successfully\n");
}

void insertFront(int USN, char Name[], char Branch[], int Sem, char phNo[]) {
  struct Node *newNode;

  newNode = (struct Node*) malloc(sizeof(struct Node));

  newNode->USN = USN;
  strcpy(newNode->Name, Name);
  strcpy(newNode->Branch, Branch);
  newNode->Sem = Sem;
  strcpy(newNode->phNo, phNo);

  newNode->next = head;
  head = newNode;

  printf("Student inserted at the front successfully\n");
}

void deleteFront() {
  struct Node *temp;

  if (head == NULL) {
    printf("List is empty\n");
    return;
  }

  temp = head;
  head = head->next;
  free(temp);

  printf("Student deleted from the front successfully\n");
}

int main() {
  int choice, n, USN, Sem;
  char Name[20], Branch[20], phNo[10];

  head = NULL;

  do {
    printf("\nMenu:\n");
    printf("1. Create a list of students\n");
    printf("2. Display the list of students\n");
    printf("3. Insert a student at the end\n");
    printf("4. Delete a student from the end\n");
    printf("5. Insert a student at the front\n");
    printf("6. Delete a student from the front\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the number of students: ");
        scanf("%d", &n);
        createList(n);
        break;
      case 2:
        displayList();
        break;
      case 3:
        printf("Enter the USN, Name, Branch, Sem, and Phone Number of the student: ");
        scanf("%d %s %s %d %s", &USN, Name, Branch, &Sem, phNo);
        insertEnd(USN, Name, Branch, Sem, phNo);
        break;
      case 4:
        deleteEnd();
        break;
      case 5:
        printf("Enter the USN, Name, Branch, Sem, and Phone Number of the student: ");
        scanf("%d %s %s %d %s", &USN, Name, Branch, &Sem, phNo);
        insertFront(USN, Name, Branch, Sem, phNo);
        break;
      case 6:
        deleteFront();
        break;
      case 7:
        printf("Exiting...\n");
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  } while (choice != 7);

  return 0;
}
