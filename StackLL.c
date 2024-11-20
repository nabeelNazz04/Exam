#include<stdio.h>
#include<stdlib.h>
struct Node{
  int data;
  struct Node*next;
};
typedef struct Node node;
node*getNode(){
  node*newNode=(node*)malloc(sizeof(newNode));
  return newNode;
}
node* push(int data,node*top){
  node*newNode=getNode();
  if(newNode==NULL){
    printf("Stack overflow");
  }
  else{
    newNode->data=data;
    newNode->next=top;
    top=newNode;
  }
  return top;
}
node*pop(node*top){
  if(top==NULL){
    printf("Empty");
  }
  else{
    printf("Deleted:%d",top->data);
    top=top->next;
  }
  return top;
}
void display(node*top){
  while(top!=NULL){
    printf("%d\t",top->data);
    top=top->next;
  }
}
void main(){
  node*top=NULL;
  int ch,data;
  while(1){
    printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch){
      case 1:
        printf("Enter the value:");
        scanf("%d",&data);
        top=push(data,top);
        break;
      case 2:
        top=pop(top);
        break;
      case 3:
        display(top);
        break;
      case 4:
        break;
      default:
        printf("invalid");
    }
  }
}