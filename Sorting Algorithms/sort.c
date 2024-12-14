#include<stdio.h>
#include<stdlib.h>
#include"SelectionSort.c"
//#include"BubbleSort.c"
#include"InsertionSort.c"
#include"CountingSort.c"
//#include"RadixSort.c"
#include"QuickSort.c"
#include"MergeSort.c"
#include"ShellSort.c"

void PrintArray(int *arr , int arrSize){
  for(int i=0;i<arrSize;i++){
    printf("%d ",arr[i]);
  }
}

int main(){
  int arr[] = {1,2,5,5,3};
  int len = sizeof(arr)/sizeof(arr[0]);
  int *parr = arr;
  int l = 0;
  int r = len-1;
  //QuickSort(parr , 0,r);
  MergeSort(parr,l,r);
  //CountingSort(parr,len);
  PrintArray(parr , len);
  return 0;
}