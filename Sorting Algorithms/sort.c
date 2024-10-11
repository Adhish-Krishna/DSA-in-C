#include<stdio.h>
#include<stdlib.h>
#include"SelectionSort.c"
//#include"BubbleSort.c"
#include"InsertionSort.c"
//#include"CountingSort.c"
#include"RadixSort.c"
#include"QuickSort.c"
#include"MergeSort.c"
#include"ShellSort.c"

void PrintArray(int *arr , int arrSize){
  for(int i=0;i<arrSize;i++){
    printf("%d ",arr[i]);
  }
}

int main(){
  int arr[] = {4,1,3,2};
  int len = 4;
  int *parr = arr;
  int l = 0;
  int r = len-1;
  QuickSort(parr , 0,r);
  PrintArray(parr , len);
  return 0;
}