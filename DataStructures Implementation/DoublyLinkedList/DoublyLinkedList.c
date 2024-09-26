#include<stdio.h>
#include<stdlib.h>

typedef struct Listnode{
  int data;
  struct Listnode *prev;
  struct Listnode *next;
}Listnode;

Listnode* CreateNode(Listnode *node , int data){
  node = (Listnode *)malloc(sizeof(Listnode));
  node->data = data;
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

void DisplayListReverse(Listnode *tail){
  Listnode *curr = tail;
  while(curr!=NULL){
    printf("%d->",curr->data);
    curr = curr->prev;
  }
  printf("NULL\n");
}

Listnode * ReturnTail(Listnode *head){
  Listnode *curr = head;
  while(curr->next != NULL){
    curr = curr->next;
  }
  return curr;
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
  Listnode* new_node = CreateNode(new_node , data);
  int curr_pos = 1;
  Listnode *curr = head;
  Listnode *next_node;
  if (position == 1 || head == NULL){
    new_node->next = head;
    head = new_node;
    new_node->prev = NULL;
    return head;
  }
  if (position==Len(head)+1){
    while(curr->next !=NULL){
      curr = curr->next;
    }
    curr->next = new_node;
    new_node->prev = curr;
    return head;
  }
  while(curr_pos<position){
    curr = curr->next;
    curr_pos++;
  }
  next_node = curr->next;
  curr->next = new_node;
  new_node->prev = curr;
  new_node->next = next_node;
  next_node->prev = new_node;
  return head;
}

Listnode * Delete(Listnode *head , int position){
  int pos = 1;
  Listnode *curr = head;
  Listnode *nextnode = NULL;
  Listnode *nextnextnode = NULL;
  while(pos<position-1){
    curr = curr->next;
    pos++;
  }
  nextnode = curr->next;
  nextnextnode = nextnode->next;
  nextnode->next = NULL;
  curr->next = nextnextnode;
  free(nextnode);
  return head;
}

Listnode * UpdateNode(Listnode *head , int position , int data){
  int pos = 1;
  Listnode *curr = head;
  while(pos<position){
    curr = curr->next;
    pos++;
  }
  curr->data = data;
  return head;
}

int GetValue(Listnode *head , int position){
  Listnode *curr = head;
  int pos = 1;
  while(pos<position){
    curr = curr->next;
    pos++;
  }
  return curr->data;
}

int BinarySearch(Listnode *head , int target){
  int low = 1;
  int high = Len(head);
  while(low<=high){
    int mid = low+(high-low)/2;
    int midVal = GetValue(head,mid);
    if(midVal == target){
      return mid;
    }
    if(midVal>target){
      high = mid-1;
    }
    if(midVal<target){
      low = mid+1;
    }
  }
  return -1;
}