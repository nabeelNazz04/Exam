#include<stdio.h>
#include<stdlib.h>
struct Node{
  int data;
  struct Node*next;
};
typedef struct Node node;
node*getNode(){
  node*newNode=(node*)malloc(sizeof(newNode));
  newNode->next=NULL;
  return newNode;
}
//Insert at end
node*insert(node*head,int data){
  node*newNode=getNode();
  newNode->data=data;
  if(head==NULL){
    head=newNode;
  }
  else{
   node*temp=head;
   while(temp->next!=NULL){
    temp=temp->next;
   }
   temp->next=newNode;
  }
  return head;
}
node*merge(node*head1,node*head2){
  node*megaHead=NULL;
  if(head1==NULL) return head2;
  if(head2==NULL) return head1;
  if(head1->data<=head2->data){
    megaHead=head1;
    megaHead->next=merge(head1->next,head2);
  }
  else{
    megaHead=head2;
    megaHead->next=merge(head1,head2->next);
  }
  return megaHead;
}
void display(node*head){
  if(head==NULL){
    printf("Empty");
    return;
  }
  node*temp=head;
  while(temp!=NULL){
    printf("%d\t",temp->data);
    temp=temp->next;
  }
}
void main(){
  node*head1=NULL;
  node*head2=NULL;
  node*head3=NULL;
  int choice,data;
  while(1){
     printf("\nMenu:\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Merge Lists\n");
        printf("6. Display Merged List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
        case 1:
          printf("Enter the value:");
          scanf("%d",&data);
          head1=insert(head1,data);
          break;
        
        case 2:
          printf("Enter the value:");
          scanf("%d",&data);
          head2=insert(head2,data);
          break;
        case 3:
          display(head1);
          break;
        case 4:
          display(head2);
          break;
        case 5:
          head3=merge(head1,head2);
          break;
        case 6:
          display(head3);
          break;
        case 7:
          exit(0);
        default:
        printf("Invalid");
        }
        }
}