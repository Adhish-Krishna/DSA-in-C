#include<stdio.h>
#include<stdlib.h>

int** CreateGraph(int size){
  int** graph = (int**)malloc(sizeof(int*)*size);
  for(int i=0;i<size;i++){
    graph[i] = (int*)calloc(sizeof(int),size);
  }
  return graph;
}

void AddEdge(int**graph , int i , int j , int weight){
  if(weight == 0){
    weight = 1;
  }
  graph[i][j] = weight;
  graph[j][i] = 0;
}

void Display(int** graph , int row , int col){
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      printf("%d ",graph[i][j]);
    }
    printf("\n");
  }
}

int main(){
  int size = 6;
  int** graph = CreateGraph(size);
  //Graph with unweighted edges
  AddEdge(graph , 1,2,0);
  AddEdge(graph , 2,3,0);
  AddEdge(graph , 3,4,0);
  AddEdge(graph , 4,5,0);
  Display(graph , 6 , 6);

/*
  //Graph with weighted edges:
  AddEdge(graph , 1 , 2 , 3);
  AddEdge(graph , 2 , 3 , 6);
  AddEdge(graph , 3 , 4 , 9);
  AddEdge(graph , 4 , 5 , 2);
  Display(graph , 6 , 6);
*/
  return 0;
}

//Note: Undirected Graphs have their matrix representation symmetric in nature
