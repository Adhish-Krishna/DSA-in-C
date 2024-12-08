#include<stdio.h>
#include<stdlib.h>

#define INT_MIN -1000000

typedef struct node{
  int data;
  struct node* next;
}node;

typedef struct Queue{
  node* front;
  node* rear;
  node* head;
}Queue;

node* CreateNode(node* newnode , int data){
  newnode = (node*)malloc(sizeof(node));
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
}

Queue* CreateQueue(Queue *queue){
  queue = (Queue*)malloc(sizeof(Queue));
  queue->head = NULL;
  queue->front = NULL;
  queue->rear = NULL;
  return queue;
}

int isEmpty(Queue* queue){
  if(queue->front == NULL){
    return 1;
  }
  return 0;
}

Queue* Enqueue(Queue* queue , int data){
  if(queue->head!=NULL){
    node* newnode = CreateNode(newnode,data);
    queue->rear->next = newnode;
    queue->rear = newnode;
  }
  else{
    queue->head = CreateNode(queue->head,data);
    queue->front = queue->head;
    queue->rear = queue->head;
    queue->head->next = NULL;
  }
  return queue;
}

Queue* Dequeue(Queue* queue){
  if(isEmpty(queue)==0){
    queue->front = queue->front->next;
    queue->head->next = NULL;
    queue->head = queue->front;
  }else{
    printf("Queue is empty");
  }
  return queue;
}

int Peek(Queue* queue){
  if(isEmpty(queue)==0){
    return queue->front->data;
  }
  else{
    return INT_MIN;
  }
}

void Print(Queue* queue){
  if(isEmpty(queue)==0){
    node* curr = queue->front;
    while(curr!=NULL){
      printf("%d ",curr->data);
      curr = curr->next;
    }
  }
  else{
    printf("NULL");
  }
}

/*
int main(){
  Queue *newqueue = CreateQueue(newqueue);
  newqueue = Enqueue(newqueue,1);
  newqueue = Enqueue(newqueue,2);
  newqueue = Enqueue(newqueue,3);
  newqueue = Enqueue(newqueue,4);
  newqueue = Enqueue(newqueue,5);
  newqueue = Enqueue(newqueue,6);
  printf("\n");
  Print(newqueue);
  newqueue = Dequeue(newqueue);
  newqueue = Dequeue(newqueue);
  newqueue = Dequeue(newqueue);
  newqueue = Dequeue(newqueue);
  printf("\n");
  Print(newqueue);
  return 0;
}
*/