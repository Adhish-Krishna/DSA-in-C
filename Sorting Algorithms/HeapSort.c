#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

void Swap(int* a , int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int GetMax(int a , int b , int l , int r){
  return (a>=b?l:r);
}

int GetParent(int index){
  if(index%2==0){
    return (index/2)-1;
  }
  return index/2;
}

int GetLeftChild(int index){
  return 2*index+1;
}

int GetRightChild(int index){
  return 2*index+2;
}

void HeapifyDOWN(int** arr , int* size , int index){
  if(index<0) return;
  int largest = index;
  int left = INT_MIN;
  int right = INT_MIN;
  int l_index = GetLeftChild(largest);
  int r_index = GetRightChild(largest);
  if(l_index < (*size)){
    left = (*arr)[l_index];
  }
  if(r_index < (*size)){
    right = (*arr)[r_index];
  }
  int max = GetMax(left , right , l_index , r_index);
  if(max<(*size) && (*arr)[max]>(*arr)[largest]){
    Swap(&(*arr)[largest] , &(*arr)[max]);
    HeapifyDOWN(arr , size , max);
  }
}

void BuildMaxHeap(int** arr , int* size){
  if(!(*arr) || (*size)==0) return;
  int non_leaf_index = (*size)/2 -1;
  while(non_leaf_index>=0){
    HeapifyDOWN(arr , size , non_leaf_index);
    non_leaf_index--;
  }
}

void DeleteRoot(int** arr , int* size){
  //swap the first and last element
  //perform HeapifyDOWN process
  if (!arr || !*arr || !size || *size <= 1) return;
  Swap(&(*arr)[0] , &(*arr)[(*size)-1]);
  (*size)--;
  HeapifyDOWN(arr, size , 0);
}

void HeapSort(int** arr , int* size){
  /*
  Algorithm:
  1) Build a Max or Min Heap from the input array
  2) Delete the root and place the root at the end of the array
  3) Repeat step 2 untill the root has no children
  4) Print or return the array
  Note: If you use Max Heap then the array will be sorted in asending order. If you use Min Heap then the array will be sorted in descending order
  */
  if (!arr || !*arr || !size || *size <= 0) return;

    int originalSize = *size;
    BuildMaxHeap(arr, size);

    while (*size > 1) {
        DeleteRoot(arr, size);
    }
    *size = originalSize;
}

void Print(int** arr , int len){
  for(int i=0;i<len;i++){
    printf("%d ",(*arr)[i]);
  }
  printf("\n");
}

int main(){
  int arr[] = {1,9,2,8,3,4,7,6,5};
  int *size;
  *size = sizeof(arr)/4;
  int* parr = arr;
  HeapSort(&parr , size);
  Print(&parr , *size);
  return 0;
}
