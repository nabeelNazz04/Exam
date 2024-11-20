#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* left;
  struct node* right;
};
typedef struct node node;

// Function to create a new node
node* getNode() {
  node* newNode = (node*)malloc(sizeof(node));
  if (!newNode) {
    printf("Memory allocation failed.\n");
    exit(1);
  }
  return newNode;
}

// Function to insert a new node into the BST
node* insert(node* root, int data) {
  node* new;
  if (root == NULL) {
    new = getNode();
    new->data = data;
    new->left = new->right = NULL;
    root = new;
    return root;
  }

  node* temp1;
  node* temp = root;

  while (temp != NULL) {
    if (data < temp->data) {
      temp1 = temp;
      temp = temp->left;
    } else if (data > temp->data) {
      temp1 = temp;
      temp = temp->right;
    } else {
      printf("Item already exists.\n");
      return root;
    }
  }

  new = getNode();
  new->data = data;
  new->left = new->right = NULL;
  if (data < temp1->data) {
    temp1->left = new;
  } else {
    temp1->right = new;
  }
  return root;
}

// Function to search for a value in the BST
node* search(node* root, int data) {
  node* temp = root;
  while (temp != NULL) {
    if (data < temp->data) {
      temp = temp->left;
    } else if (data > temp->data) {
      temp = temp->right;
    } else {
      return temp; // Match found
    }
  }
  return NULL; // Not found
}

// Inorder traversal to display the tree
void inorder(node* root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
  }
}

int main() {
  node* root = NULL;
  int data, ch;
  node* k;

  while (1) {
    printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch) {
      case 1:
        printf("Enter the value: ");
        scanf("%d", &data);
        root = insert(root, data);
        break;
      case 2:
        printf("Enter the value: ");
        scanf("%d", &data);
        k = search(root, data);
        if (k != NULL) {
          printf("Item found: %d\n", k->data);
        } else {
          printf("Item not found\n");
        }
        break;
      case 3:
        printf("Inorder Traversal: ");
        inorder(root);
        printf("\n");
        break;
      case 4:
        printf("Exiting...\n");
        exit(0);
        break;
      default:
        printf("Invalid choice.\n");
        break;
    }
  }
  return 0;
}
