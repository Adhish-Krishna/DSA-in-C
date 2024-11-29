#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> // for using bool datatype
#include<limits.h> // for using INT_MAX
#include<string.h> // for using memcpy function

void Swap(int* a , int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int getMin(int a , int b , int l , int r){
  return (a<b?l:r);
}

int GetParentIndex(int curr_index){
  int parent_index = 0;
  if(curr_index%2==0){
    parent_index = curr_index/2 - 1;
  }
  else{
    parent_index = curr_index/2;
  }
  return (parent_index>=0?parent_index:0);
}

int GetLeftChildIndex(int parent_index){
  return (2*parent_index+1);
}

int GetRightChildIndex(int parent_index){
  return (2*parent_index+2);
}

void HeapifyDOWN(int** heap , int* size , int curr_index){
  if (!heap || !*heap || !size || curr_index < 0) return;

    int l_index = GetLeftChildIndex(curr_index);
    int r_index = GetRightChildIndex(curr_index);
    int left = INT_MAX;
    int right = INT_MAX;

    if (l_index < *size) {
        left = (*heap)[l_index];
    }
    if (r_index < *size) {
        right = (*heap)[r_index];
    }

    int min = getMin(left, right, l_index, r_index);
    if (min < *size && (*heap)[curr_index] > (*heap)[min]) {
        Swap(&(*heap)[curr_index], &(*heap)[min]);
        HeapifyDOWN(heap, size, min);
    }
}

void HeapifyUP(int** heap , int* size , int curr_index){
  if (!heap || !*heap || !size || curr_index <= 0) return;
  int parent_index = GetParentIndex(curr_index);
  if((*heap)[curr_index]<(*heap)[parent_index] && curr_index>=0){
    Swap(&(*heap)[curr_index] , &(*heap)[parent_index]);
    HeapifyUP(heap , size , parent_index);
  }
}

void Insert(int** heap , int element , int* size){
  if(!heap || !size) return;
  if(*heap == NULL){
    *heap = (int*)malloc(sizeof(int));
    (*size) +=1;
  }
  else{
    *heap = (int*)realloc(*heap,sizeof(int)*(*size+1));
    (*size)+=1;
  }
  (*heap)[*size-1] = element;
  int curr_index = *size -1;
  int parent_index = GetParentIndex(curr_index);
  while(curr_index>=0 && ((*heap)[curr_index]<(*heap)[parent_index])){
    Swap(&(*heap)[curr_index] , &(*heap)[parent_index]);
    curr_index = parent_index;
    parent_index = GetParentIndex(curr_index);
  }
}

void DeleteRoot(int** heap , int* size){
  if(*heap == NULL || *size<=0){
    return;
  }
  (*heap)[0] = (*heap)[*size-1];
  (*size)--;
  int *temp = (int*)realloc(*heap , sizeof(int)*(*size));
  if(temp !=NULL){
    *heap = temp;
  }
  int parent_index = 0;
  int l_index = GetLeftChildIndex(parent_index);
  int r_index = GetRightChildIndex(parent_index);
  int smallest = parent_index;
  if(l_index<*size && (*heap)[l_index]<(*heap)[smallest]){
    smallest = l_index;
  }
  if(r_index<*size && (*heap)[r_index]<(*heap)[smallest]){
    smallest = r_index;
  }
  int min = smallest;
  while((((*heap)[parent_index]>(*heap)[min]))&& parent_index<(*size)){
    Swap(&(*heap)[parent_index] , &(*heap)[min]);
    parent_index = min;
    l_index = GetLeftChildIndex(parent_index);
    r_index = GetRightChildIndex(parent_index);
    if(l_index<*size && (*heap)[l_index]<(*heap)[smallest]){
      smallest = l_index;
    }
    if(r_index<*size && (*heap)[r_index]<(*heap)[smallest]){
      smallest = r_index;
    }
    min = smallest;
  }
}

int Peek(int** heap){
  if (!heap || !*heap) return INT_MIN;
  return (*heap)[0];
}

void BuildHeapFromArray(int** heap , int* size){
  if (!heap || !*heap || !size || *size <= 0) return;
  int curr_index = (*size / 2) - 1;
  while (curr_index >= 0) {
    HeapifyDOWN(heap, size, curr_index);
    curr_index--;
  }
}

bool isLeaf(int** heap , int *size ,int index){
  int l_index = GetLeftChildIndex(index);
  if(l_index>=*size){
    return true;
  }
  return false;
}

bool isEmpty(int* size){
  return (*size==0?true:false);
}

void PrintHeap(int** heap , int* size){
  if(!heap || !*heap || !size) return;
  for(int i=0;i<*size;i++){
    printf("%d ",(*heap)[i]);
  }
}

int main() {
    int *heap = NULL;
    int *size;
    *size = 0;

    printf("\n=== Testing isEmpty and Peek ===\n");
    printf("Empty heap check: %s\n", isEmpty(size) ? "true" : "false");
    printf("Peek empty heap: %d\n", Peek(&heap));

    printf("\n=== Testing Insert ===\n");
    // Insert into empty heap
    Insert(&heap, 5, size);
    printf("After inserting 5: ");
    PrintHeap(&heap, size);
    printf("\n");

    // Insert multiple elements
    Insert(&heap, 3, size);
    Insert(&heap, 7, size);
    Insert(&heap, 1, size);
    Insert(&heap, 4, size);
    printf("After inserting 3,7,1,4: ");
    PrintHeap(&heap, size);
    printf("\n");
    printf("Peek after inserts: %d\n", Peek(&heap));
    printf("isEmpty check: %s\n", isEmpty(size) ? "true" : "false");

    printf("\n=== Testing DeleteRoot ===\n");
    printf("Before delete: ");
    PrintHeap(&heap, size);
    printf("\n");
    DeleteRoot(&heap, size);
    printf("After first delete: ");
    PrintHeap(&heap, size);
    printf("\n");
    DeleteRoot(&heap, size);
    printf("After second delete: ");
    PrintHeap(&heap, size);
    printf("\n");

    printf("\n=== Testing BuildHeapFromArray ===\n");
    int arr[] = {10, 5, 15, 1, 3, 7, 20};
    *size = 7;
    heap = (int*)malloc(sizeof(arr));
    memcpy(heap, arr, sizeof(arr));
    printf("Before heapify: ");
    PrintHeap(&heap, size);
    printf("\n");
    BuildHeapFromArray(&heap, size);
    printf("After heapify: ");
    PrintHeap(&heap, size);
    printf("\n");

    printf("\n=== Testing isLeaf ===\n");
    printf("Is index 0 leaf? %s\n", isLeaf(&heap, size, 0) ? "true" : "false");
    printf("Is index 5 leaf? %s\n", isLeaf(&heap, size, 5) ? "true" : "false");

    printf("\n=== Testing Combined Operations ===\n");
    // Clear heap
    free(heap);
    heap = NULL;
    *size = 0;

    // Sequence of operations
    Insert(&heap, 10, size);
    Insert(&heap, 20, size);
    printf("After inserting 10,20: ");
    PrintHeap(&heap, size);
    printf("\n");

    DeleteRoot(&heap, size);
    printf("After deleting root: ");
    PrintHeap(&heap, size);
    printf("\n");

    Insert(&heap, 5, size);
    printf("After inserting 5: ");
    PrintHeap(&heap, size);
    printf("\n");

    printf("Final peek: %d\n", Peek(&heap));
    printf("Final size: %d\n", *size);

    // Edge cases
    printf("\n=== Testing Edge Cases ===\n");
    DeleteRoot(&heap, size);
    DeleteRoot(&heap, size);
    DeleteRoot(&heap, size); // Try deleting from empty heap
    printf("After deleting everything: ");
    PrintHeap(&heap, size);
    printf("\n");
    printf("isEmpty: %s\n", isEmpty(size) ? "true" : "false");

    if (heap) {
        free(heap);
        heap = NULL;
    }

    *size = 0;

    // Testing Heapify Up Function
    printf("\n=== Testing HeapifyUP ===\n");

    // Test 1: Empty heap (should handle gracefully)
    printf("Test 1 - Empty heap:\n");
    HeapifyUP(&heap, size, 0);
    printf("Result: ");
    PrintHeap(&heap, size);
    printf("\n");

    // Test 2: Single element
    heap = (int*)malloc(sizeof(int));
    heap[0] = 5;
    *size = 1;
    printf("\nTest 2 - Single element:\n");
    HeapifyUP(&heap, size, 0);
    printf("Result: ");
    PrintHeap(&heap, size);
    printf("\n");

    // Test 3: Multiple elements requiring heapification
    int arr10[] = {3, 7, 8, 12, 2}; // Add 2 which should bubble up
    *size = 5;
    heap = (int*)realloc(heap, *size * sizeof(int));
    memcpy(heap, arr10, *size * sizeof(int));
    printf("\nTest 3 - Before HeapifyUP at index 4: ");
    PrintHeap(&heap, size);
    HeapifyUP(&heap, size, 4); // Heapify at index 4 (value 2)
    printf("\nAfter HeapifyUP: ");
    PrintHeap(&heap, size);
    printf("\n");

    // Test 4: Edge case - trying to heapify root
    printf("\nTest 4 - Heapify at root:\n");
    HeapifyUP(&heap, size, 0);
    printf("Result: ");
    PrintHeap(&heap, size);
    printf("\n");

    // Test 5: Duplicate values
    int arr2[] = {4, 4, 8, 12, 4};
    *size = 5;
    memcpy(heap, arr2, *size * sizeof(int));
    printf("\nTest 5 - Before HeapifyUP with duplicates: ");
    PrintHeap(&heap, size);
    HeapifyUP(&heap, size, 4);
    printf("\nAfter HeapifyUP: ");
    PrintHeap(&heap, size);
    printf("\n");

    // Cleanup
    if (heap) {
        free(heap);
        heap = NULL;
    }

    return 0;
}
