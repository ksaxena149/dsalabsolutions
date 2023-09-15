// Stack using array

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