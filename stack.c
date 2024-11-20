#include<stdio.h>
#define N 10
int stack[N];
int top = -1;

int isEmpty() {
  return (top == -1);
}

int isFull() {
  return (top == N - 1);
}

void push(int item) {
  if(isFull()) {
    printf("Stack is full\n");
  } else {
    top++;
    stack[top] = item;
  }
}

int pop() {
  if(isEmpty()) {
    printf("Stack is empty\n");
    return -1; // Indicate an empty stack
  } else {
    return stack[top--];
  }
}

void display() {
  if(top == -1) {
    printf("Stack underflow\n");
  } else {
    printf("\nStack is:\n");
    for(int i = 0; i <= top; i++) {
      printf("%d\t", stack[i]);
    }
    printf("\n");
  }
}

void main() {
  int ch, item;
  while(1) {
    printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice: ");
    scanf("%d", &ch);
    switch(ch) {
      case 1:
        printf("Enter the value: ");
        scanf("%d", &item);
        push(item);
        break;
      case 2:
        if(!isEmpty()) {
          printf("Popped value is %d\n", pop());
        } else {
          pop();
        }
        break;
      case 3:
        display();
        break;
      case 4:
        return;
      default:
        printf("Invalid choice\n");
    }
  }
}
