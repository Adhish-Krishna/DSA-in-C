void Swap(int *arr , int i1 , int i2){
	int temp = arr[i1];
	arr[i1] = arr[i2];
	arr[i2] = temp;
}

void BubbleSort(int *arr, int arrSize){
	int toSwap = 0;
	for(int i=0;i<arrSize;i++){
		toSwap = 0;
		for(int j=0;j<arrSize-i-1;j++){
			if(arr[j]>arr[j+1]){
				Swap(arr,j,j+1);
				toSwap++;
			}
		}
		if(toSwap == 0){
			break;
		}
	}
}
