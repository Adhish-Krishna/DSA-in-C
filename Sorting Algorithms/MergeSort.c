void Merge(int *arr , int l , int m , int r){
  int len1 = m-l+1;
  int len2 = r-m;
  int* left =(int*)malloc(len1*sizeof(int));
  int* right =(int*)malloc(len2*sizeof(int));
  for(int i=0;i<len1;i++){
    left[i] = arr[l+i];
  }
  for(int i=0;i<len2;i++){
    right[i] = arr[m+1+i];
  }
  int i=0;
  int j=0;
  int k=l;
  while(i<len1 && j<len2){
    if(left[i]<=right[j]){
      arr[k] = left[i];
      i++;
    }else{
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
  free(left);
  free(right);
}

void MergeSort(int *arr , int l , int r){
  if(l<r){
    int m = l + (r-l)/2;
    MergeSort(arr , l , m);
    MergeSort(arr , m+1 , r);
    Merge(arr , l , m , r);
  }
}
