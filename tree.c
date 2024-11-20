#include<stdio.h>
#include<stdlib.h>
#define N 5

struct node {
  int data;
  struct node*left;
  struct node*right;
};

struct que {
  struct node*q[N];
  int front;
  int rear;
};

int isEmpty(struct que*q) {
  if(q->front == -1 && q->rear == -1){
    return 1;
  }
  return 0;
}

struct node*getNode() {
  struct node*newNode = (struct node*)malloc(sizeof(struct node));
  return newNode;
}

void enque(struct que*q, struct node*item) {
  if (q->rear == N - 1) {
    printf("Queue is full\n");
  } else if (q->front == -1 && q->rear == -1) {
    q->front = q->rear = 0;
    q->q[q->rear] = item;
  } else {
    q->rear = q->rear + 1;
    q->q[q->rear] = item;
  }
}

struct node*deq(struct que*q) {
  struct node*item;
  if (q->front == -1 && q->rear == -1) {
    printf("Queue is empty\n");
    return NULL;
  } else {
    item = q->q[q->front];
    if (q->front == q->rear) {
      q->front = q->rear = -1;
    } else {
      q->front = q->front + 1;
    }
  }
  return item;
}

struct node*insert(struct node*root, struct que*q, int data) {
  struct node*new = getNode();
  new->data = data;
  new->left = NULL;
  new->right = NULL;
  if (root == NULL) {
    return new;
  } else {
    enque(q, root);
    while (!isEmpty(q)) {
      struct node*temp = deq(q);
      if (temp->left != NULL && temp->right != NULL) {
        enque(q, temp->left);
        enque(q, temp->right);
      } else if (temp->left == NULL) {
        temp->left = new;
        break;
      } else if (temp->right == NULL) {
        temp->right = new;
        break;
      }
    }
  }
  return root;
}

void levelOrder(struct node*root, struct que*q) {
  q->front=q->rear=-1;
  enque(q, root);
  while (!isEmpty(q)) {
    struct node*temp = deq(q);
    printf("%d\t", temp->data);
    if (temp->left != NULL) {
      enque(q, temp->left);
    }
    if (temp->right != NULL) {
      enque(q, temp->right);
    }
  }
}
void inorder(struct node*root){
  if(root!=NULL){
  inorder(root->left);
  printf("%d\t",root->data);
  inorder(root->right);
  }
}

int main() {
  struct que q;
  q.front = q.rear = -1;
  struct node*root = NULL;
  while (1) {
    printf("\n1.Insert\n2.Display\n3.Exit\nEnter your choice: ");
    int ch, data;
    scanf("%d", &ch);
    switch (ch) {
      case 1:
        printf("Enter the data: ");
        scanf("%d", &data);
        root = insert(root, &q, data);
        break;
      case 2:
        //levelOrder(root, &q);
        inorder(root);
        break;
      case 3:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}
