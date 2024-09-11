#include<stdio.h>
#include<stdlib.h>

void PrintArray(int *arr, int len){
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
}

int Insert(int *arr , int len , int pos , int element){
    len++;
    arr = (int*)realloc(arr,(len)*sizeof(int));
    for(int i=len-1;i>pos;i--){
        arr[i] = arr[i-1];
    }
    arr[pos] = element;
    return len;
}

int Update(int *arr , int len , int pos , int ele){
    arr[pos] = ele;
    return len;
}

int Delete(int *arr , int len , int pos){
    for(int i=pos;i<len-1;i++){
        arr[i] = arr[i+1];
    }
    len--;
    arr = (int*)realloc(arr,(len)*sizeof(int));
    return len;

}

int Exchange(int *arr , int pos1 , int pos2 , int len){
    int temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
    return len;
}

void Sort(int *arr , int arrSize){
    int i=1;
    int j=0;
    int key;
    for(i=1;i<arrSize;i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int Search(int *arr , int arrSize , int target){
    int low = 0;
    int high = arrSize-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid]>target){
            high = mid-1;
        }
        if(arr[mid]<target){
            low = mid+1;
        }
    }
    return -1;
}

void Reverse(int *arr , int start , int end){
    while(start<end){
        int temp;
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void Rotate(int *arr , int k , int len){
    k = k%len;
    Reverse(arr,0,len-1);
    Reverse(arr,0,k-1);
    Reverse(arr,k,len-1);
}

int* Merge(int *arr1 , int *arr2 , int len1 , int len2){
    int i=0;
    int j=0;
    int reslen=0;
    int *resarr = (int*)malloc((len1+len2)*sizeof(int));
    while(i<len1 && j<len2){
        if(arr1[i] < arr2[j]){
            resarr[reslen] = arr1[i];
            i++;
        }
        else{
            resarr[reslen] = arr2[j];
            j++;
        }
        reslen++;
    }
    while(i<len1){
        resarr[reslen] = arr1[i];
        i++;
        reslen++;
    }
    while(j<len2){
        resarr[reslen] = arr2[j];
        j++;
        reslen++;
    }
    return resarr;
}

int* Copy(int *arr , int len){
    int *newarr = (int*)malloc(len*sizeof(int));
    for(int i=0;i<len;i++){
        newarr[i] = arr[i];
    }
    return newarr;
}

int* SplitArr(int **arr , int arrSize , int splitpos){
    int *newarr = (int*)malloc((arrSize-splitpos)*sizeof(int));
    int *newarr1 = (int*)malloc(splitpos*sizeof(int));
    for(int i=splitpos;i<arrSize;i++){
        newarr[i-splitpos] = (*arr)[i];
    }
    for(int i=0;i<splitpos;i++){
        newarr1[i] = (*arr)[i];
    }
    free(*arr);
    *arr = newarr1;
    return newarr;
}

int main() {
    int arrlen;
    printf("Enter the size of the input array:");
    scanf("%d",&arrlen);
    printf("\nEnter the elements for the array:");
    int *arr = (int *)malloc(arrlen * sizeof(int));
    for (int i = 0; i < arrlen; i++) {
        scanf("%d",&arr[i]);
    }

    int choice, pos, element, len, target, k, len1, len2;
    int *arr2, *mergedArr;

    do {
        printf("\nMenu:\n");
        printf("1. Print Array\n");
        printf("2. Insert Element\n");
        printf("3. Update Element\n");
        printf("4. Delete Element\n");
        printf("5. Exchange Elements\n");
        printf("6. Sort Array in Ascending Order\n");
        printf("7. Sort Array in Descending Order:\n");
        printf("8. Search Element\n");
        printf("9. Reverse Array\n");
        printf("10. Rotate Array\n");
        printf("11. Merge Arrays\n");
        printf("12. Copy Array\n");
        printf("13. Split Array\n");
        printf("14. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Current Array: ");
                PrintArray(arr, arrlen);
                break;
            case 2:
                printf("Enter position and element to insert: ");
                scanf("%d %d", &pos, &element);
                arrlen = Insert(arr, arrlen, pos, element);
                break;
            case 3:
                printf("Enter position and new element: ");
                scanf("%d %d", &pos, &element);
                arrlen = Update(arr, arrlen, pos, element);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                arrlen = Delete(arr, arrlen, pos);
                break;
            case 5:
                printf("Enter positions of elements to exchange: ");
                int pos1, pos2;
                scanf("%d %d", &pos1, &pos2);
                arrlen = Exchange(arr, pos1, pos2, arrlen);
                break;
            case 6:
                Sort(arr, arrlen);
                printf("Array sorted.\n");
                PrintArray(arr,arrlen);
                break;
            case 7:
                Sort(arr,arrlen);
                Reverse(arr,0,arrlen-1);
                printf("Array sorted.\n");
                PrintArray(arr,arrlen);
                break;
            case 8:
                printf("Enter element to search: ");
                scanf("%d", &target);
                pos = Search(arr, arrlen, target);
                if (pos != -1) {
                    printf("Element %d found at position %d.\n", target, pos);
                } else {
                    printf("Element %d not found.\n", target);
                }
                break;
            case 9:
                printf("Enter start and end indices to reverse: ");
                int start, end;
                scanf("%d %d", &start, &end);
                Reverse(arr, start, end);
                printf("Array reversed.\n");
                break;
            case 10:
                printf("Enter number of positions to rotate: ");
                scanf("%d", &k);
                Rotate(arr, k, arrlen);
                printf("Array rotated.\n");
                break;
            case 11:
                printf("Enter length of second array: ");
                scanf("%d", &len2);
                arr2 = (int *)malloc(len2 * sizeof(int));
                printf("Enter elements of second array:\n");
                for (int i = 0; i < len2; i++) {
                    scanf("%d", &arr2[i]);
                }
                mergedArr = Merge(arr, arr2, arrlen, len2);
                printf("Merged Array: ");
                free(arr);
                arr = mergedArr;
                arrlen = arrlen+len2;
                PrintArray(mergedArr, arrlen);
                free(arr2);
                free(mergedArr);
                break;
            case 12:
                {
                    int *newarr = Copy(arr, arrlen);
                    printf("Copied Array: ");
                    PrintArray(newarr, arrlen);
                    free(newarr);
                }
                break;
            case 13:
                {
                int splitpos;
                printf("Enter the split position:");
                scanf("%d",&splitpos);
                int *resarr = SplitArr(&arr,arrlen,splitpos);
                printf("\nArray Splitted\n");
                PrintArray(arr,splitpos);
                printf("\n");
                PrintArray(resarr , arrlen-splitpos);
                free(resarr);
                arrlen = splitpos;
                }
                break;
            case 14:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 14);

    free(arr);
    return 0;
}
