#include<stdio.h>
#include<stdlib.h>
#include"DirectedGraph.c"

#define INT_MIN -100000000

typedef struct Stack{
    int size;
    int *stack;
    int top;
}Stack;

Stack* CreateStack(Stack *Stack , int size){
    Stack->stack = (int*)malloc(size*sizeof(int));
    Stack->size = size;
    Stack->top = -1;
    return Stack;
}

int isEmpty(Stack* Stack){
    if(Stack->top ==-1){
        return 1;
    }else{
        return 0;
    }
}

Stack* Push(Stack* Stack , int data){
    if(isFull(Stack)==0){
        Stack->top ++ ;
        Stack->stack[Stack->top] = data;
    }
    else{
        printf("Stack is full");
    }
    return Stack;
}

Stack* Pop(Stack* Stack){
    if(isEmpty(Stack)==0){
        Stack->top--;
    }else{
        printf("Stack is Empty");
    }
    return Stack;
}

int Peek(Stack* Stack){
    if(isEmpty(Stack)==0){
        return Stack->stack[Stack->top];
    }
    return INT_MIN;
}

void DFS(Graph* g, Stack* st , int i, int* visited){
  if(visited == NULL){
    visited = (int*)calloc(sizeof(int), g->N);
  }
  if(visited[i] == 0){
    visited[i] = 1;
    Node* curr = g->List[i];
    while(curr!=NULL){
      if(visited[curr->data]!=1){
        DFS(g, st, curr->data, visited);
      }
      curr = curr->next;
    }
    st = Push(st, i);
  }
}

void TopologicalSort(Graph* g, Stack* st, int* visited){
  if(visited == NULL){
    visited = (int*)calloc(sizeof(int), g->N);
  }
  if(st == NULL){
    st = (Stack*)malloc(sizeof(Stack));
    st = CreateStack(st,g->N);
  }
  for(int i=0;i<g->N;i++){
    if(visited[i]==0){
      DFS(g,st,i,visited);
    }
  }
  while(isEmpty(st)!=1){
    printf("%d ",Peek(st));
    st = Pop(st);
  }
}

int main(){
  Graph* g = CreateGraph(5,true);
  g = AddEdge(g,0,1);
  g = AddEdge(g,0,3);
  g = AddEdge(g,1,2);
  g = AddEdge(g,1,3);
  g = AddEdge(g,2,4);
  g = AddEdge(g,3,4);
  int* visited = NULL;
  Stack* st = NULL;
  TopologicalSort(g,st,visited);
  return 0;
}