int * ShellSort(int *arr , int arrSize){
  int gap = arrSize/2;
  while(gap>=1)
  {
    for(int i=gap;i<arrSize;i++){
      int temp = arr[i];
      int j=i;
      while(j>=gap&&arr[j-gap]>temp){
        arr[j] = arr[j-gap];
        j-=gap;
      }
      arr[j] = temp;
    }
    gap = gap/2;
  }
  return arr;
}
