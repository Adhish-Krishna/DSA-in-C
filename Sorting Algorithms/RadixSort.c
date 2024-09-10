#include<stdlib.h>

int getMax(int *arr , int arrSize){
  int max=arr[0];
  for(int i=0;i<arrSize;i++){
    if(arr[i]>max){
      max = arr[i];
    }
  }
  return max;
}

void CountingSort(int *arr , int arrSize , int exp){
  int count[10] = {0};
  int *output = (int*)malloc(arrSize*sizeof(int));
  for(int i=0;i<arrSize;i++){
    count[(arr[i]/exp)%10]++;
  }
  for(int i=1;i<10;i++){
    count[i] = count[i]+count[i-1];
  }
  for(int i=arrSize-1;i>=0;i--){
    output[count[(arr[i]/exp)%10]-1] = arr[i];
    count[(arr[i]/exp)%10]--;
  }
  for(int i=0;i<arrSize;i++){
    arr[i] = output[i];
  }
  free(output);
}

void RadixSort(int *arr , int arrSize){
  int max = getMax(arr,arrSize);
  for(int exp=1; max/exp>0;exp*=10){
    CountingSort(arr,arrSize,exp);
  }
}