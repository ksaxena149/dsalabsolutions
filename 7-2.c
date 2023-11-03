#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct CircularQueue {
  char items[MAX];
  int front, rear;
};

void insert(struct CircularQueue* cq, char item) {
  if ((cq->front == 0 && cq->rear == MAX - 1) || (cq->front == cq->rear + 1)) {
    overflow();
    return;
  }

  if (cq->front == -1) {
    cq->front = 0;
    cq->rear = 0;
  } else if (cq->rear == MAX - 1) {
    cq->rear = 0;
  } else {
    cq->rear++;
  }

  cq->items[cq->rear] = item;
}

char delete(struct CircularQueue* cq) {
  if (cq->front == -1) {
    underflow();
    return '\0';
  }

  char item = cq->items[cq->front];

  if (cq->front == cq->rear) {
    cq->front = -1;
    cq->rear = -1;
  } else if (cq->front == MAX - 1) {
    cq->front = 0;
  } else {
    cq->front++;
  }

  return item;
}

void display(struct CircularQueue cq) {
  if (cq.front == -1) {
    printf("Queue is empty\n");
    return;
  }

  printf("Queue elements: ");
  if (cq.rear >= cq.front) {
    for (int i = cq.front; i <= cq.rear; i++) {
      printf("%c ", cq.items[i]);
    }
  } else {
    for (int i = cq.front; i < MAX; i++) {
      printf("%c ", cq.items[i]);
    }
    for (int i = 0; i <= cq.rear; i++) {
      printf("%c ", cq.items[i]);
    }
  }
  printf("\n");
}

void overflow() {
  printf("Queue is full\n");
}

void underflow() {
  printf("Queue is empty\n");
}

void main() {
  struct CircularQueue cq;
  cq.front = -1;
  cq.rear = -1;
  int choice;
  char item;

  while (1) {
    printf("\nCircular Queue Operations:\n");
    printf("1. Insert an element\n");
    printf("2. Delete an element\n");
    printf("3. Display the queue\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the element to be inserted: ");
        scanf(" %c", &item);
        insert(&cq, item);
        break;
      case 2:
        item = delete(&cq);
        printf("Deleted element: %c\n", item);
        break;
      case 3:
        display(cq);
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }
}
