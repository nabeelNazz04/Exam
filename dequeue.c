#include<stdio.h>
#include<stdlib.h>
#define N 5

int s[N], rear = -1, front = -1;

void enqueFront(int item) {
    if ((front == 0 && rear == N - 1) || (front == rear + 1)) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) { // First element
        front = rear = 0;
    } else if (front == 0) { // Wrap around
        front = N - 1;
    } else {
        front--;
    }
    s[front] = item;
}

void enqueRear(int item) {
    if ((front == 0 && rear == N - 1) || (front == rear + 1)) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) { // First element
        front = rear = 0;
    } else {
        rear = (rear + 1) % N; // Circular increment
    }
    s[rear] = item;
}
int dequeuefront(){
  if(front==-1 && rear==-1){
    return -1;
    }
  else{
    int item1=s[front];
    if(front==rear){//only one element
      front=rear=-1;
    }
    else{
      front=(front+1)%N;
    }
    return item1;
  }
}
int dequeuerear(){
  if(front==-1 && rear==-1){
    return -1;
  }
  else{
    int item=s[rear];
    if(rear==front){
      front=rear=-1;
    }
    else{
      rear--;
    }
    return item;
  }
}
void display() {
    if (front == -1 && rear == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements are: ");
    if (front <= rear) {
        for (int i = front; i <= rear; i++) {
            printf("%d\t", s[i]);
        }
    } else {
        for (int i = front; i < N; i++) {
            printf("%d\t", s[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d\t", s[i]);
        }
    }
    printf("\n");
}

void main() {
    int ch, data;
    while (1) {
        printf("\n1. Enqueue front\n2. Enqueue rear\n3.Dequeue front\n4.Dequeue rear\n5. Display\n6. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &data);
                enqueFront(data);
                break;
            case 2:
                printf("Enter the value: ");
                scanf("%d", &data);
                enqueRear(data);
                break;
            case 3:
            if(front==-1 && rear==-1){
              printf("Queueu is empty");
            }
            else{
               data=dequeuefront();
               printf("Removed %d",data);
            }
              break;
            case 4:
              if(front==-1 && rear==-1){
              printf("Queueu is empty");
            }
            else{
               data=dequeuerear();
               printf("Removed %d",data);
            }
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
}
