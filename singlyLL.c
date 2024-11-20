#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to insert at the end of the list
struct Node *enqueueRear(struct Node *head, int newData) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        struct Node *current = head;
        while (current->next != NULL)
            current = current->next;
        current->next = newNode;
    }
    return head;
}

// Function to display the linked list
void displayLinkedList(struct Node *head) {
    if (head == NULL)
        printf("\nList is Empty!");
    else {
        struct Node *current = head;
        printf("\nLinked List: ");
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL");
    }
}

// Function to merge two sorted linked lists
struct Node *mergeSortedLists(struct Node *list1, struct Node *list2) {
    struct Node dummy;
    struct Node *current = &dummy;
    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    // Attach remaining nodes
    if (list1 != NULL)
        current->next = list1;
    else
        current->next = list2;

    return dummy.next;
}

int main() {
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;
    struct Node *mergedList = NULL;

    printf("Welcome to Linked List Merging!\n");

    int choice;
    while (1) {
        printf("\nMenu:");
        printf("\n1) Create First Sorted List");
        printf("\n2) Create Second Sorted List");
        printf("\n3) Merge the Two Lists");
        printf("\n4) Display First List");
        printf("\n5) Display Second List");
        printf("\n6) Display Merged List");
        printf("\n7) Exit");
        printf("\nChoose an operation: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int n, val;
                printf("\nEnter the number of elements for the first list: ");
                scanf("%d", &n);
                printf("\nEnter %d sorted elements: ", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &val);
                    list1 = enqueueRear(list1, val);
                }
                break;
            }
            case 2: {
                int n, val;
                printf("\nEnter the number of elements for the second list: ");
                scanf("%d", &n);
                printf("\nEnter %d sorted elements: ", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &val);
                    list2 = enqueueRear(list2, val);
                }
                break;
            }
            case 3:
                mergedList = mergeSortedLists(list1, list2);
                printf("\nLists Merged Successfully!");
                break;
            case 4:
                printf("\nFirst List:");
                displayLinkedList(list1);
                break;
            case 5:
                printf("\nSecond List:");
                displayLinkedList(list2);
                break;
            case 6:
                printf("\nMerged List:");
                displayLinkedList(mergedList);
                break;
            case 7:
                printf("\nExiting the Program.");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.");
        }
    }
    return 0;
}
