#include<stdio.h>
#include<stdlib.h>

void SmallestAndSecondSmallest(int *arr , int arrSize , int *s , int *ss){
  *s = __INT_MAX__;
  *ss = __INT_MAX__;
  for(int i=0;i<arrSize;i++){
    if(arr[i]<*s){
      *s = arr[i];
    }
    if(arr[i]>*s && arr[i]<*ss){
      *ss = arr[i];
    }
  }
}

int main(){
  int arr[] = {6,8,3,0,1};
  int len = 5;
  int *parr = arr;
  int s;
  int ss;
  SmallestAndSecondSmallest(parr,len,&s,&ss);
  printf("Smallest: %d",s);
  printf("\nSecond Smallest: %d",ss);
  return 0;
}