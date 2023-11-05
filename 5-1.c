// Stack using array
// Design, Develop and Implement a menu driven Program in C for the following 
// operations on STACK of Integers (Array Implementation of Stack with 
// maximum size MAX)
// a. Push an Element on to Stack
// b. Pop an Element from Stack
// c. Demonstrate how Stack can be used to check Palindrome
// d. Demonstrate Overflow and Underflow situations on Stack
// e. Display the status of Stack
// f. Exit. Support the program with appropriate functions for each of the above 
// operations.

#include <stdio.h>

struct Stack {
  int arr[10];
  int top;
} st;

void push(int n){
  if(st.top==10){
    printf("Stack is full\n");
    return;
  }
  st.arr[st.top] = n;
  st.top++;
}

void pop(){
  if(st.top==0){
    printf("Stack is empty\n");
    return;
  }
  st.top--;
}

void display(){
  for(int i = 0; i<st.top; i++){
    printf("%d ", st.arr[i]);
  }
  printf("\n");
}

int main(){
  st.top=0;
  push(5);
  push(4);
  push(3);
  pop();
  display();
  return 0;
}