#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

struct stack
{
  int stack[MAX];
  int top;
};

struct stack st = { {0}, -1 };

void push(int num) {
  if(st.top == MAX - 1) {
    printf("Stack Overflow\n");
    return;
  }
  st.top++;
  st.stack[st.top] = num;
  printf("%d pushed to stack\n", num);
}

void pop() {
  if(st.top == -1) {
    printf("Stack Underflow\n");
    return;
  }
  printf("%d popped from stack\n", st.stack[st.top]);
  st.top--;
}

void palindrome() {
  char str[MAX];
  printf("Enter a string: ");
  scanf("%s", str);
  int len = strlen(str);
  for(int i = 0; i < len/2; i++) {
    push(str[i]);
  }
  int i;
  if(len % 2 == 0) {
    i = len/2;
  } else {
    i = len/2 + 1;
  }
  for(; i < len; i++) {
    if(str[i] != st.stack[st.top]) {
      printf("%s is not a palindrome\n", str);
      return;
    }
    pop();
  }
  printf("%s is a palindrome\n", str);
}

void overflow() {
  int i = 12;
  while (st.top!=MAX)
  {
    push(i++);
  }
  
}

void underflow() {
  while(st.top != -1) {
    pop();
  }
}

void display() {
  if(st.top == -1) {
    printf("Stack is empty\n");
    return;
  }
  printf("Stack elements are: ");
  for(int i = st.top; i >= 0; i--) {
    printf("%d ", st.stack[i]);
  }
  printf("\n");
}

int main() {
  int choice, num;
  while(1) {
    printf("\n\nSTACK OPERATIONS\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Check Palindrome\n");
    printf("4. Overflow\n");
    printf("5. Underflow\n");
    printf("6. Display\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        printf("Enter the element to push: ");
        scanf("%d", &num);
        push(num);
        break;
      case 2:
        pop();
        break;
      case 3:
        palindrome();
        break;
      case 4:
        overflow();
        break;
      case 5:
        underflow();
        break;
      case 6:
        display();
        break;
      case 7:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}
