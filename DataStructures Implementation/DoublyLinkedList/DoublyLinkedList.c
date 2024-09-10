#include<stdio.h>
#include<stdlib.h>

typedef struct Listnode{
  int data;
  struct Listnode *prev;
  struct Listnode *next;
}Listnode;

Listnode* CreateNode(Listnode *node){
  node = (Listnode *)malloc(sizeof(Listnode));
  node->data = 5;
  node->prev = NULL;
  node->next = NULL;
  return node;
}

void DisplayList(Listnode *head){
  Listnode *current = head;
  while(current != NULL){
    printf("%d->",current->data);
    current = current->next;
  }
  printf("NULL\n");
}

Listnode* InsertNode(Listnode* head , int position , int data){


}

int main(){

  Listnode *head = CreateNode(head);
  DisplayList(head);

return 0;
}