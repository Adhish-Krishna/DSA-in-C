#include<stdio.h>
#include<stdlib.h>
#include"DirectedGraph.c"
#include "../../Queue/Using Linked List/SimpleQueue.c"

void BFS(Graph* graph){
  int* visited = (int*)calloc(graph->N,sizeof(int));
  Queue* queue = CreateQueue(queue);
  queue = Enqueue(queue , graph->List[0]->data);
  visited[graph->List[0]->data] = 1;
  printf("%d ",queue->front->data);
  while(!isEmpty(queue)){
    Node* curr = graph->List[queue->front->data];
    queue = Dequeue(queue);
    while(curr!=NULL){
      if(visited[curr->data]!=1){
        visited[curr->data] = 1;
        queue = Enqueue(queue , curr->data);
        printf("%d ",curr->data);
      }
      curr = curr->next;
    }
  }
  free(visited);
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
  printf("BFS\n");
  BFS(graph);
}