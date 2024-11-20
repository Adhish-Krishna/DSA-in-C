#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node{
  int data;
  struct node* prev;
  struct node* next;
}node;

node* CreateNode(int data){
  node* newnode = (node*)malloc(sizeof(node));
  newnode->data = data;
  newnode->prev = NULL;
  newnode->next = NULL;
  return newnode;
}

node* InsertNode(node* head , int data){
  node* newnode = CreateNode(data);
  if(head == NULL){
    head = newnode;
    return head;
  }
  else{
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
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

int FindMax(node* head){
  node* curr = head;
  int max = INT_MIN;
  while(curr!=NULL){
    if(curr->data > max){
      max = curr->data;
    }
    curr = curr->next;
  }
  return max;
}

int* CreateArray(node* head){
  int len = FindMax(head);
  int* arr = (int*)calloc(sizeof(int),(len+1));
  return arr;
}

void DeleteNode(node* head , node** delnode){
  if(head == NULL){
    return;
  }
  if((*delnode)->prev == NULL){
    head = (*delnode)->next;
    if(head!=NULL){
      head->prev = NULL;
    }
  }
  else if((*delnode)->next == NULL){
    (*delnode)->prev->next = NULL;
    (*delnode)->prev = NULL;
  }
  else{
    (*delnode)->prev->next = (*delnode)->next;
    (*delnode)->next->prev = (*delnode)->prev;
  }
  free((*delnode));
}

node* RemoveDuplicates(node* head){
  int* arr = CreateArray(head);
  node* curr = head;
  while(curr!=NULL){
    if(arr[curr->data] == 0){
      arr[curr->data] += 1;
    }
    else{
      DeleteNode(head , &curr);
    }
    curr = curr->next;
  }
  free(arr);
  return head;
}

int main(){
  int n;
  node* head = NULL;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    int val;
    scanf("%d",&val);
    head = InsertNode(head,val);
  }
  head = RemoveDuplicates(head);
  Print(head);
  return 0;
}