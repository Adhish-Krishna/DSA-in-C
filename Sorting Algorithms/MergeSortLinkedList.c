#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node* next;
}node;

node* CreateNode(int data){
  node* newnode = (node*)malloc(sizeof(node));
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
}

node* Insert(node* head , int data){
  node* newnode = CreateNode(data);
  if(head == NULL){
    head = newnode;
    return head;
  }
  else{
    node* curr = head;
    while(curr->next!=NULL){
      curr = curr->next;
    }
    curr->next = newnode;
    return head;
  }
}

void Print(node* head){
  node* curr = head;
  while(curr!=NULL){
    printf("%d ",curr->data);
    curr = curr->next;
  }
}

node* SplitList(node* head){
  node* slow = head;
  node* fast = head;
  node* prev = NULL;
  while(fast!=NULL && fast->next!=NULL){
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  return prev;
}

node* Merge(node* head1 , node* head2){
  node* sortednode = NULL;
  node* s = NULL;
  if(head1 == NULL)return head2;
  if(head2 == NULL)return head1;
  if(head1 && head2){
    if(head1->data < head2->data){
      s = head1;
      head1 = head1->next;
    }else{
      s = head2;
      head2 = head2->next;
    }
    sortednode = s;
  }
  while(head1 && head2){
    if(head1->data < head2->data){
      s->next = head1;
      s = head1;
      head1 = head1->next;
    }else{
      s->next = head2;
      s = head2;
      head2 = head2->next;
    }
  }
  if(head1){
    s->next = head1;
  }
  if(head2){
    s->next = head2;
  }
  return sortednode;
}

node* MergeSort(node* head){
  if(head == NULL || head->next == NULL){
    return head;
  }
  node* mid = SplitList(head);
  node* head1 = mid->next;
  mid->next = NULL;
  head = MergeSort(head);
  /*Debug Statements
  printf("\n");
  Print(head);
  */
  head1 = MergeSort(head1);
  /*Debug Statements
  printf("\n");
  Print(head1);
  */
  return Merge(head, head1);
}

int main(){
  int arr[] = {1,2,3,4,5,2,3,4,5};
  int len = sizeof(arr)/4;
  node* head = NULL;
  for(int i=0;i<len;i++){
    head = Insert(head,arr[i]);
  }
  Print(head);
  head = MergeSort(head);
  printf("\n");
  Print(head);
  return 0;
}