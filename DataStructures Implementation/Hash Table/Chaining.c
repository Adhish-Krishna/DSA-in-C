#include<stdio.h>
#include<stdlib.h>
#include"Hash.c"

typedef struct Node{
  int data;
  struct Node* next;
}Node;

typedef struct HashTable{
  int size;
  Node** table;
}HashTable;

Node* CreateNode(int data){
  Node* newnode = (Node*)malloc(sizeof(Node));
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
}

Node* Insertnode(Node* head , int data){
  Node* newnode = CreateNode(data);
  if(head== NULL){
    head = newnode;
  }
  else{
    Node* curr = head;
    while(curr->next!=NULL){
      curr = curr->next;
    }
    curr->next = newnode;
  }
  return head;
}

HashTable* CreateTable(int size){
  HashTable* hashtable = (HashTable*)malloc(sizeof(HashTable));
  hashtable->size = size;
  hashtable->table = (Node**)malloc(size*sizeof(Node*));
  for(int i=0;i<size;i++){
    hashtable->table[i] = NULL;
  }
  return hashtable;
}

HashTable* InsertIntoTable(HashTable* hashtable , int key , int val){
  int hash = MidSquareMethod(key , hashtable->size); //Used Division method for hashing
  hashtable->table[hash] = Insertnode(hashtable->table[hash] , val);
  return hashtable;
}

void DisplayTable(HashTable* hashtable){
  for(int i=0; i<hashtable->size; i++){
    Node* curr = hashtable->table[i];
    while(curr!=NULL){
      printf("%d->",curr->data);
      curr = curr->next;
    }
    printf("NULL");
    printf("\n");
  }
}

int main(){
  HashTable* hashtable = CreateTable(11);
  hashtable = InsertIntoTable(hashtable , 0 , 3);
  hashtable = InsertIntoTable(hashtable , 1 , 3);
  hashtable = InsertIntoTable(hashtable , 2 , 45);
  hashtable = InsertIntoTable(hashtable , 3 , 43);
  hashtable = InsertIntoTable(hashtable , 4 , 23);
  hashtable = InsertIntoTable(hashtable , 5 , 34);
  hashtable = InsertIntoTable(hashtable , 6 , 35);
  hashtable = InsertIntoTable(hashtable , 7 , 36);
  hashtable = InsertIntoTable(hashtable , 8 , 38);
  hashtable = InsertIntoTable(hashtable , 9 , 39);
  hashtable = InsertIntoTable(hashtable , 10 , 34);
  DisplayTable(hashtable);
}
