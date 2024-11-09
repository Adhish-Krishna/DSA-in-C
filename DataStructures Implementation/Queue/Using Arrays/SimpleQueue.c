#include<stdio.h>
#include<stdlib.h>

#define INT_MIN -10000000

typedef struct Queue{
  int size;
  int front;
  int rear;
  int *queue;
}Queue;

Queue* CreateQueue(Queue* newq, int size){
  newq = (Queue*)malloc(sizeof(Queue));
  newq->size = size;
  newq->queue = (int*)malloc(newq->size*sizeof(int));
  newq->front = -1;
  newq->rear = -1;
  return newq;
}

int isEmpty(Queue* newq){
  if(newq->front == newq->rear){
    return 1;
  }
  return 0;
}

int isFull(Queue* newq){
  if(newq->rear == newq->size-1){
    return 1;
  }
  return 0;
}

Queue* Enqueue(Queue* newq , int data){
  if(isEmpty(newq)==1){
    newq->front = 0;
  }
  if(isFull(newq)==0){
    newq->rear++;
    newq->queue[newq->rear] = data;
  }
  return newq;
}

Queue* Dequeue(Queue* newq){
  if(isEmpty(newq)==0){
    newq->front++;
  }
  return newq;
}

int Peek(Queue* newq){
  if(isEmpty(newq)==0){
    return newq->queue[newq->front];
  }else{
    return INT_MIN;
  }
}

void Print(Queue* newq){
  int index = newq->front;
  while(index<=newq->rear && index!=-1){
    printf("%d ",newq->queue[index]);
    index++;
  }
}

int main(){
  Queue* newq = CreateQueue(newq,10);
  newq = Enqueue(newq,1);
  newq = Enqueue(newq,2);
  newq = Enqueue(newq,3);
  newq = Enqueue(newq,4);
  newq = Enqueue(newq,5);
  Print(newq);
  printf("\n");
  newq = Dequeue(newq);
  newq = Dequeue(newq);
  newq = Dequeue(newq);
  Print(newq);
  printf("\n");
  int n = Peek(newq);
  printf("%d",n);
  return 0;
}