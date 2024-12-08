#include<stdio.h>
#include<stdlib.h>
#include"DirectedGraph.c"
#include"../../Stack/Using Linked List/Stack-Implementation-in-Linked-List.c"

void DFS(Graph* graph , Node* node ,  int* visited){
  if(visited == NULL){
    visited = (int*)calloc(sizeof(int) , graph->N);
  }
  printf("%d ",node->data);
  visited[node->data] = 1;
  Node* curr = graph->List[node->data];
  while(curr!=NULL){
    if(visited[curr->data]!=1){
      DFS(graph , curr , visited);
    }
    curr = curr->next;
  }
}

int main(){
  Graph* graph = CreateGraph(6 , true);
  graph = AddEdge(graph , 0 , 3);
  graph = AddEdge(graph , 0 , 2);
  graph = AddEdge(graph , 0 , 5);
  graph = AddEdge(graph , 5 , 2);
  graph = AddEdge(graph , 5 , 3);
  graph = AddEdge(graph , 5 , 1);
  graph = AddEdge(graph , 3 , 1);
  graph = AddEdge(graph , 4 , 5);
  graph = AddEdge(graph , 4 , 0);
  graph = AddEdge(graph , 2 , 3);
  graph = AddEdge(graph , 1 , 0);
  graph = AddEdge(graph , 3 , 4);
   printf("Adjaceny List Representation\n");
  Display(graph);
  printf("DFS\n");
  int* visited = NULL;
  DFS(graph , graph->List[0] , visited);
}