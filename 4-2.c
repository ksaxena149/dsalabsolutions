#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  int regNo;
  float CGPA;
  struct Node* next;
}*head;

void createList(int n) {
  int i, regNo;
  float CGPA;

  struct Node *newNode, *temp;

  for (i = 0; i < n; i++) {
    printf("Enter the RegNo and CGPA of student %d: ", i + 1);
    scanf("%d %f", &regNo, &CGPA);

    newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->regNo = regNo;
    newNode->CGPA = CGPA;
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
  printf("Grades of students:\n");
  p = head;
  while (p != NULL) {
    printf("Reg No: %d\n", p->regNo);
    printf("CGPA: %f\n", p->CGPA);
    printf("\n");

    p = p->next;
  }
}

void main(){
  int choice, n, regNo, CGPA;

  head = NULL;

  do {
    printf("\nMenu:\n");
    printf("1. Create a list of students\n");
    printf("2. Display the list of students\n");
    printf("3. Exit\n");
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
        printf("Exiting...\n");
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  } while (choice != 3);
}