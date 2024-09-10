#include<stdio.h>
#include<stdlib.h>
#include"SelectionSort.c"
//#include"BubbleSort.c"
#include"InsertionSort.c"
//#include"CountingSort.c"
#include"RadixSort.c"
#include"QuickSort.c"
#include"MergeSort.c"

void PrintArray(int *arr , int arrSize){
  for(int i=0;i<arrSize;i++){
    printf("%d ",arr[i]);
  }
}

int main(){
  int arr[] = {1,8,6,4,9,0,3,6,2,8,2,8,9,5,6,4,3,1,7,5};
  int len = 20;
  int *parr = arr;
  int l = 0;
  int r = len-1;
  QuickSort(parr , l , r);
  PrintArray(parr , len);
  return 0;
}