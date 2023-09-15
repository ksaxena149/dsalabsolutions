// Implement stack using linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Stack {
  struct Node* top;
};

void push(struct Stack* st, int n) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = n;
  newNode->next = st->top;
  st->top = newNode;
}

void pop(struct Stack* st) {
  if(st->top == NULL) {
    printf("Stack is empty\n");
    return;
  }
  struct Node* temp = st->top;
  st->top = st->top->next;
  free(temp);
}

void display(struct Stack* st) {
  if(st->top == NULL) {
    printf("Stack is empty\n");
    return;
  }
  struct Node* temp = st->top;
  while(temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  struct Stack st;
  st.top = NULL;
  push(&st, 5);
  push(&st, 4);
  push(&st, 3);
  display(&st);
  pop(&st);
  display(&st);
  push(&st, 2);
  push(&st, 1);
  push(&st, 0);
  display(&st);
  return 0;
}