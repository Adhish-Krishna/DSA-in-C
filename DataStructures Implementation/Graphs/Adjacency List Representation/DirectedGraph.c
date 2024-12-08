#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
  int data;
  struct Node* next;
}Node;


typedef struct Graph{
  int N;
  Node** List;
  bool isDirected;
}Graph;

Node* CreateListNode(int data){
  Node* newnode = (Node*)malloc(sizeof(Node));
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
}

Graph* CreateGraph(int N , bool isDirected){
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->N = N;
  graph->isDirected = isDirected;
  graph->List = (Node**)malloc(graph->N*sizeof(Node*));
  for(int i=0;i<graph->N;i++){
    graph->List[i] = CreateListNode(i);
  }
  return graph;
}

Graph* AddEdge(Graph* graph , int src , int dest){
  Node* dest_node = CreateListNode(dest);
  Node* src_node = CreateListNode(src);
  if(graph->List[src] == NULL){
    graph->List[src] = src_node;
    src_node->next = dest_node;
  }
  else{
    Node* curr = graph->List[src];
    while(curr->next!=NULL){
      curr = curr->next;
    }
    curr->next = dest_node;
    if(graph->isDirected == false){
      Node* new_curr = graph->List[dest];
      while(new_curr->next != NULL){
        new_curr = new_curr->next;
      }
      new_curr->next = CreateListNode(src);
    }
  }
  return graph;
}

void DisplayList(Node* head){
  Node* curr = head;
  while(curr!=NULL){
    printf("%d->",curr->data);
    curr = curr->next;
  }
  printf("NULL\n");
}

void Display(Graph* graph){
  for(int i=0;i<graph->N;i++){
    DisplayList(graph->List[i]);
  }
}


/*
int main(){
  Graph* graph = CreateGraph(5 , true);
  graph = AddEdge(graph , 0 , 1);
  graph = AddEdge(graph , 0 , 2);
  graph = AddEdge(graph , 0 , 3);
  graph = AddEdge(graph , 1 , 2);
  graph = AddEdge(graph , 1 , 3);
  graph = AddEdge(graph , 2 , 3);
  graph = AddEdge(graph , 3 , 4);
  Display(graph);
  return 0;
}
*/