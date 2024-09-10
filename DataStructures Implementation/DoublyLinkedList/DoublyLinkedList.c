#include<stdio.h>
#include<stdlib.h>

typedef struct Listnode{
  int data;
  struct Listnode *prev;
  struct Listnode *next;
}Listnode;

Listnode* CreateNode(Listnode *node){
  node = (Listnode *)malloc(sizeof(Listnode));
  node->data = 0;
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

int Len(Listnode *head){
  Listnode *curr = head;
  int len = 1;
  while(curr->next !=NULL){
    len++;
    curr = curr->next;
  }
  return len;
}

Listnode* InsertNode(Listnode* head , int position , int data){
  Listnode* new_node = CreateNode(new_node);
  new_node->data = data;
  int curr_pos = 1;
  Listnode *curr = head;
  Listnode *next_node;
  if (position == 1){
    head->data = data;
    return head;
  }
  if (position==Len(head)+1){
    while(curr->next !=NULL){
      curr = curr->next;
    }
    curr->next = new_node;
    return head;
  }
  while(curr_pos<position){
    curr = curr->next;
    curr_pos++;
  }
  next_node = curr->next;
  curr->next = new_node;
  new_node->next = next_node;
  return head;
}

int main(){

  Listnode *head = CreateNode(head);
  for(int i=1;i<11;i++){
    head = InsertNode(head,i,i);
  }
  printf("Length: %d\n",Len(head));
  DisplayList(head);

return 0;
}