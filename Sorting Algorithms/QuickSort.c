void Swap(int *a , int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int Partition(int *arr , int low , int high){
  int pivot = arr[high];
  int i = low-1;
  for(int j=low;j<high;j++){
    if(arr[j]<pivot){
      i++;
      Swap(&arr[i],&arr[j]);
    }
  }
  Swap(&arr[i+1],&arr[high]);
  return i+1;
}

void QuickSort(int *arr , int low , int high){
  if(low<high){
    int pi = Partition(arr,low,high);
    QuickSort(arr,low,pi-1);
    QuickSort(arr,pi+1,high);
  }
}
