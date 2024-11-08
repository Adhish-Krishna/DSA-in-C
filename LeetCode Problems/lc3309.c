#include<stdio.h>
#include<stdlib.h>

void Swap(int *a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int *Reverse(int *arr , int s , int e){
  while(s<e){
    Swap(&arr[s],&arr[e]);
    s++;
    e--;
  }
  return arr;
}

void PrintArray(int *arr , int arrSize){
  for(int i=0;i<arrSize;i++){
    printf("%d ",arr[i]);
  }
}

int * NextPermutation(int *arr , int arrSize){
  // look for the ith index such that arr[i] < arr[i+1]
  int i;
  int j;
  for(i=arrSize-2;i>=0;i--){
    if(arr[i]<arr[i+1]){
      break;
    }
  }
  // if no such index exists then return NULL that is it is the last permutation
  if(i==-1){
    return NULL;
  }
  // if such index exists then search for the index j from the end of the array such that arr[j]>arr[i]
  else{
    for(j=arrSize-1;j>i;j--){
      if(arr[j]>arr[i]){
        break;
      }
    }
    // swap them
    Swap(&arr[i],&arr[j]);
    //reverse the array from i+1 to arrSize -1
    arr = Reverse(arr,i+1,arrSize-1);
  }
  return arr;
}

int maxGoodNumber(int* nums, int numsSize){
  qsort(nums,numsSize,sizeof(int),compare);
  int max_sum_arr[8];
  int max_sum_count = 0;
  while(nums!=NULL){
    // bin array to store three 8-bit binary numbers
    int *bin = (int*)malloc(24*sizeof(int));
    // converts each integer into it's binary
    int bin_index = 0;
    for(int i=0;i<numsSize;i++){
        int curr_num = nums[i];
        int count = 0;
        while(curr_num>0){
            int bit = curr_num&1;
            bin[bin_index] = bit;
            bin_index++;
            curr_num = curr_num>>1;
            count++;
        }
        //concatenating the binary numbers
        bin = Reverse(bin , bin_index-count, bin_index-1);
    }
    //converts the binary string into a number
    int max_sum = 0;
    int power2 = 1;
    for(int i=bin_index-1;i>=0;i--){
        max_sum += bin[i]*power2;
        power2 *= 2;
    }
    max_sum_arr[max_sum_count] = max_sum;
    max_sum_count++;
    nums = NextPermutation(nums,numsSize);
    free(bin);
  }
  int max = 0;
  for(int i=0;i<max_sum_count;i++){
    if(max_sum_arr[i]>max){
      max = max_sum_arr[i];
    }
  }
  PrintArray(max_sum_arr,max_sum_count);
  return max;
}

int main(){
  int arr[] = {1,11,15};
  int *parr = arr;
  int len = 3;
  int max = maxGoodNumber(parr,len);
  printf("%d",max);
  return 0;
}