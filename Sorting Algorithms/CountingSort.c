#include<stdlib.h>

void CountingSort(int *arr , int arrSize){
  int max = arr[0];
  for(int i=0;i<arrSize;i++){
    if(arr[i]>max){
      max = arr[i];
    }
  }
  int* count = (int*)malloc((max+1)*sizeof(int));
  int* output = (int*)malloc(arrSize*sizeof(int));
  for(int i=0;i<max+1;i++){
    count[i]=0;
  }
  for(int i=0;i<arrSize;i++){
    count[arr[i]]++;
  }
  for(int i=1;i<max+1;i++){
    count[i] = count[i]+count[i-1];
  }
  for(int i=arrSize-1;i>=0;i--){
    output[count[arr[i]]-1] = arr[i];
    count[arr[i]]--;
  }
  for(int i=0;i<arrSize;i++){
    arr[i] = output[i];
  }
  free(count);
  free(output);
}