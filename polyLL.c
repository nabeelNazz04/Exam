#include<stdio.h>
#include<stdlib.h>
struct Node{
  int coeff;
  int expo;
  struct Node*next;
};
typedef struct Node node;
node* getNode(){
  node*newNode=(node*)malloc(sizeof(newNode));
  return newNode;
}
node*insert(node*head,int co,int ex){
  node*new=getNode();
  new->coeff=co;
  new->expo=ex;
  new->next=NULL;
  if(head==NULL || head->expo>ex){//Insert at front
    new->next=head;
    head=new;
  }
  else{
    node*temp=head;
    while(temp->next!=NULL && temp->next->expo>ex){//Insert at random
      temp=temp->next;
    }
    new->next=temp->next;
    temp->next=new;
  }
  return head;
}
node*create(node*head){
  int n;
  printf("Enter the number of terms:");
  scanf("%d",&n);
  int coeff,expo;
  for(int i=0;i<n;i++){
    printf("Enter the coefficient %d:",i+1);
    scanf("%d",&coeff);
    printf("Enter the exponent %d",i+1);
    scanf("%d",&expo);
    head=insert(head,coeff,expo);
}
  return head;
}
void display(node*head){
  if(head==NULL){
    printf("empty");
  }
  else{
    node*temp=head;
    while(temp!=NULL){
      printf("%dx^%d",temp->coeff,temp->expo);
      temp=temp->next;
      if(temp!=NULL){
        printf("+");
      }
      else{
        printf("\n");
      }
    }
  }
}
void main(){
  node*head=NULL;
  printf("Enter the polynomial\n");
  head=create(head);
  display(head);
}