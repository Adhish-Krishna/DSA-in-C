void Merge(int *arr , int l , int m , int r){
  int len1 = m-l+1;
  int len2 = r-m;
  int left[len1];
  int right[len2];
  for(int i=0;i<len1;i++){
    left[i] = arr[i];
  }
  for(int i=0;i<len2;i++){
    right[i] = arr[len1+i];
  }
  int i,j,k = 0;
  while(i<len1 && j<len2){
    if(left[i]<right[j]){
      arr[k] = left[i];
      i++;
    }
    if(right[j]<left[i]){
      arr[k] = right[j];
      j++;
    }
    k++;
  }
  while(i<len1){
    arr[k] = left[i];
    k++;
    i++;
  }
  while(j<len2){
    arr[k] = right[j];
    j++;
    k++;
  }
}

void MergeSort(int *arr , int l , int r){
  int m = l + (r-l)/2;
  if(l<r){
    MergeSort(arr , l , m);
    MergeSort(arr , m+1 , r);
    Merge(arr , l , m , r);
  }
}

