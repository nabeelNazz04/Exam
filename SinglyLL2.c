#include<stdio.h>
#include<stdlib.h>
struct Node{
  int data;
  struct Node*next;
};
typedef struct Node node;
node* getNode(){
  node*newNode=(node*)malloc(sizeof(newNode));
  return newNode;
}
node*insert_beg(node*header,int data){
  node*newNode=getNode();
  if(newNode==NULL){
    printf("Insufficient memory");
  }
  else{
    newNode->data=data;
    newNode->next=header;
    header=newNode;
  }
  return header;
}
node* insert_end(node*header,int data){
  node*newNode=getNode();
  newNode->data=data;
  newNode->next=NULL;
  node*temp=header;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=newNode;
  return header;
}
node*insert_rand(node*header,int data,int key){
  node*newNode=getNode();
  newNode->data=data;
  newNode->next=NULL;
  if(newNode==NULL){
    printf("Insufficient memory");
  }
  node*temp=header;
  while(temp->next!=NULL && temp->data!=key){
    temp=temp->next;
  }
  if(temp->data==key){
    newNode->next=temp->next;
    temp->next=newNode;
  }
  else if(temp->next==NULL){
    temp->next=newNode;
  }
  return header;
}
node*del_beg(node*header){
  node*temp=header;
  if(header==NULL){
    printf("Empty");
  }  printf("Removed element is:%d\n",temp->data);
  header=temp->next;
  free(temp);
  return header;
}
node*del_end(node*header){
  if(header==NULL){
    printf("Empty");
  }
  else{
  node*temp=header;
  while(temp->next->next!=NULL){
    temp=temp->next;
  }
  printf("Deleted:%d",temp->next->data);
  temp->next=NULL;
  }
  return header;
}
node*del_rand(node*header,int key){
  node*temp=header;
  while(temp->next->data!=key){
    temp=temp->next;
  }
  node*temp1=temp->next;
  temp->next=temp1->next;
  printf("Deleted:%d",temp1->data);
  free(temp1);
  return header;
}
void display(node*header){
  while(header!=NULL){
    printf("%d\t",header->data);
    header=header->next;
  }
}
void main(){
  node*header=NULL;
  while(1){
    int ch,value,key;
    printf("\n1.Insert beginning\n2.Insert end\n3.Insert random\n4.Delete beginning\n5.Delete end\n6.Delete random\n7.Display\n8.Exit\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch){
      case 1:
        printf("Enter the value:");
        scanf("%d",&value);
        header=insert_beg(header,value);
        break;
      case 2:
        printf("Enter the value:");
        scanf("%d",&value);
        header=insert_end(header,value);
        break;
      case 3:
        printf("Enter the data:");
        scanf("%d",&value);
        printf("Enter the key:");
        scanf("%d",&key);
        header=insert_rand(header,value,key);
        break;
      case 4:
        header=del_beg(header);
        break;
      case 5:
        header=del_end(header);
        break;
      case 6:
        printf("Enter the key");
        scanf("%d",&key);
        header=del_rand(header,key);
        break;
      case 7:
        display(header);
        break;
      case 8:
        exit(1);
      default:
        printf("invalid");
    }
  }
}